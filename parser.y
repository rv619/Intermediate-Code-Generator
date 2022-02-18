%{
    #include <bits/stdc++.h>
    using namespace std;
  
    // A random unknown value that fills up the space that has to be backpatched at some point of time.
    #define UNKNOWN -9999

    FILE* symbol_table_file;

    extern FILE* yyin;
    extern FILE* yyout;
    extern int yylineno;
  
    // To store Quadruples for Code Generation.
    struct Quadruple
    {
    	char *result; // result
    	char *addr1;  // address 1
    	char *op;     // operator
    	char *addr2;  // address 2
    	char *addr3;  // address 3
    	int label;    // jump instuction number
    };

    vector <Quadruple> quadruples;

    int next_instruction_index = 0;
    int temp_id_index = 1;
    int label_index = 0;
    int scope_no = -1;
    
    char* create_temporary_identifier (void);
    char* create_label (void);
    void generate_code (const char *, const char *, const char *, const char *, const char *, int);
    void generate_code (const char *, const char *, const char *, const char *);
    void generate_code (const char *, const char *, const char *);
    void generate_code (const char *, const char *);
    void generate_code (const char *, int);
    void generate_code (const char *);
    void associate_labels (void);
    void write_intermediate_code (void);
    
    vector <int> makeList (int);
    vector <int> mergeLists (vector <int> &, vector <int> &);
    void backpatch (vector <int> &, int);
    
    struct Error
    {
	char *error_message;    // Error Message
        int line_no;            // Line Number
    };

    vector <Error> errors;
    
    void add_error (const char *, int);
    void write_errors (void);    

    // Mapping identifiers (type-integers) with scope no.
    unordered_map <string, int> scope;

    // Mapping active identifiers with declaration line no.
    unordered_map <string, int> active_identifiers;

    // Holding the symbol table attributes (identifier, declaration line no., removal line no.).
    vector <pair <string, pair <int, int> > > symbol_table;

    // Stores the destination of the backpatched instructions.
    set <int> destination_instructions;

    // Mapping instructions with labels.
    unordered_map <int, char *> labels;
    
    // Stores the list of active scopes.
    vector <int> active_scopes;

    // Stores the identifiers present in a given scope.
    vector <vector <string> > identifiers;

    int add_new_scope (void);
    int remove_current_scope (void);
    void insert_identifier (char *, int);
    bool value_comparator (pair <string, pair <int, int> > &, pair <string, pair <int, int> > &);
    void write_symbol_table (void);
    
    int yylex(void);
    void yyerror(const char *);
%}

%code requires
{
    #include <bits/stdc++.h>
    using namespace std;
    
    struct Primary
    {
        char *addr;
    };
    
    struct DecisionTree
    {
        char *addr;
        vector <int> *trueList; // True List
        vector <int> *falseList; // False List
    };
    
    struct NextInstruction
    {
        int nextIns; // Next instruction number
    };
    
    struct List
    {
        vector <int> *nextList; // Next list of instructions
    };
}
%union
{
    List statementType;
    Primary arithmeticExpressionType;
    DecisionTree booleanExpressionType;
    Primary identifierType;
    Primary constantType;
    Primary operatorType;
    NextInstruction markerMType;
    List markerNType;
    int scope;
}

%token <constantType> INTEGER_CONSTANT 
%token <identifierType> IDENTIFIER
%token IF
%token THEN
%token ELSE
%token END
%token REPEAT
%token UNTIL
%token READ
%token WRITE
%token ASSIGN
%token PLUS MINUS TIMES DIVIDE MODULO
%token LESS_THAN GREATER_THAN EQUAL
%token LEFT_PAREN RIGHT_PAREN
%token SEMICOLON

%type <statementType> statement_list statement read_statement write_statement assignment_statement conditional_statement
%type <arithmeticExpressionType> arithmetic_expression multiplicative_expression unary_expression primary_expression 
%type <booleanExpressionType> boolean_expression  
%type <markerMType> marker_m
%type <markerNType> marker_n
%type <operatorType> RELOP ARITHOP MULOP
%type <scope> ADD_SCOPE REM_SCOPE 

%start program

%%
program:
        ADD_SCOPE statement_list marker_m REM_SCOPE
	{
	    backpatch (*($2.nextList), $3.nextIns);
	    generate_code ("end of program");
	}
        ;
        
statement_list:
                statement_list marker_m statement
                {
                    backpatch (*($1.nextList), $2.nextIns);
                    *($$.nextList) = *($3.nextList);
                }
                | statement
		{
		    *($$.nextList) = *($1.nextList);
		}
                ;
                
statement:
            read_statement
            {
                *($$.nextList) = *($1.nextList);
            }
            | write_statement
            {
                *($$.nextList) = *($1.nextList);
            }
            | assignment_statement
            {
                *($$.nextList) = *($1.nextList);
            }
            | conditional_statement
            {
                *($$.nextList) = *($1.nextList);
            }
            ;
            
read_statement:
                READ IDENTIFIER SEMICOLON
                {
		    $$.nextList = new vector <int> ();
    		    string identifier ($2.addr, find($2.addr, $2.addr + 128, '\0'));
                    if (active_identifiers.find(identifier) == active_identifiers.end())
		    {
			insert_identifier ($2.addr, yylineno);
		    }
                    generate_code ("read", $2.addr);
                }
                ;
                
write_statement:
                WRITE IDENTIFIER SEMICOLON
                {
		    $$.nextList = new vector <int> ();
    		    string identifier ($2.addr, find($2.addr, $2.addr + 128, '\0'));
                    if (active_identifiers.find(identifier) == active_identifiers.end())
                    {
			add_error (string{"variable '" + identifier + "' not declared in current scope"}.data(), yylineno);
                    }
		    generate_code ("write", $2.addr);
                }
                ;
                
assignment_statement:
                        IDENTIFIER ASSIGN arithmetic_expression SEMICOLON
                        {
			    $$.nextList = new vector <int> ();
			    string identifier ($1.addr, find($1.addr, $1.addr + 128, '\0'));
                    	    if (active_identifiers.find(identifier) == active_identifiers.end())
                    	    {
				insert_identifier ($1.addr, yylineno);
                    	    }
                            generate_code ($1.addr, $3.addr);
                        }
                        ;
                        
arithmetic_expression:
                        arithmetic_expression ARITHOP multiplicative_expression
                        {
                            $$.addr = create_temporary_identifier ();
                            generate_code ($$.addr, $1.addr, $2.addr, $3.addr);
                        }
                        | multiplicative_expression
                        {
                            $$.addr = $1.addr;
                        }
                        ;
                        
multiplicative_expression:
                            multiplicative_expression MULOP unary_expression
                            {
                                $$.addr = create_temporary_identifier ();
                                generate_code ($$.addr, $1.addr, $2.addr, $3.addr);
                            }
                            | unary_expression
                            {
                                $$.addr = $1.addr;
                            }
                            ;
                            
unary_expression:
                    ARITHOP unary_expression
                    {
                        $$.addr = create_temporary_identifier ();
                        generate_code ($$.addr, $1.addr, $2.addr);
                    }
                    | primary_expression
                    {
                        $$.addr = $1.addr;
                    }
                    ;
                            
primary_expression:
                    IDENTIFIER
                    {
                        $$.addr = $1.addr;
			string identifier ($1.addr, find($1.addr, $1.addr + 128, '\0'));
                        if (active_identifiers.find(identifier) == active_identifiers.end())
                        {
			    add_error (string{"variable '" + identifier + "' not declared in current scope"}.data(), yylineno);
                        }
                    }
                    | INTEGER_CONSTANT
                    {
                        $$.addr = $1.addr;
                    }
                    | LEFT_PAREN arithmetic_expression RIGHT_PAREN
                    {
                        $$.addr = $2.addr;    
                    }
                    ;

ARITHOP:  
        PLUS
        {
            $$.addr = (char *) "+";
        }
        | MINUS
        {
            $$.addr = (char *) "-";
        }
        ;
        
MULOP:  
        TIMES
        {
            $$.addr = (char *) "*";
        }
        | DIVIDE
        {
            $$.addr = (char *) "/";
        }
        | MODULO
        {
            $$.addr = (char *) "%";
        }
        ;
        
conditional_statement:
                        IF boolean_expression THEN ADD_SCOPE marker_m statement_list REM_SCOPE END
                        {
			    $$.nextList = new vector <int> ();
                            backpatch (*($2.trueList), $5.nextIns);
                            *($$.nextList) = mergeLists (*($2.falseList), *($6.nextList));
                        }
                        | IF boolean_expression THEN ADD_SCOPE marker_m statement_list marker_n REM_SCOPE
                          ELSE ADD_SCOPE marker_m statement_list REM_SCOPE END
                        {
			    $$.nextList = new vector <int> ();
                            backpatch (*($2.trueList), $5.nextIns);
                            backpatch (*($2.falseList), $11.nextIns);
                            vector <int> temp = mergeLists (*($6.nextList), *($7.nextList));
                            *($$.nextList) = mergeLists (temp, *($12.nextList));
                        }
                        | REPEAT ADD_SCOPE marker_m statement_list REM_SCOPE UNTIL boolean_expression SEMICOLON
                        {
			    $$.nextList = new vector <int> ();
                            backpatch (*($7.falseList), $3.nextIns);
                            *($$.nextList) = mergeLists (*($4.nextList), *($7.trueList));
                        }
                        ;
        
boolean_expression:
                    arithmetic_expression RELOP arithmetic_expression
                    {
			$$.trueList = new vector <int> ();
			$$.falseList = new vector <int> ();
			*($$.trueList) = makeList (next_instruction_index);
                        *($$.falseList) = makeList (next_instruction_index + 1);
                        generate_code ("if", $1.addr, $2.addr, $3.addr, "goto", UNKNOWN);
                        generate_code ("goto", UNKNOWN);
                    }
                    ;
  
RELOP:  
        LESS_THAN
        {
            $$.addr = (char *) "<";
        }
        | GREATER_THAN
        {
            $$.addr = (char *) ">";
        }
        | EQUAL
        {
            $$.addr = (char *) "==";
        }
        ;
        
marker_m:
            {
                $$.nextIns = next_instruction_index;
            }
            ;
            
marker_n:
            {
		$$.nextList = new vector <int> ();
                *($$.nextList) = makeList (next_instruction_index);
                generate_code ("goto", UNKNOWN);
            }
            ;

ADD_SCOPE:
	    {
		$$ = add_new_scope ();
	    }
	    ;


REM_SCOPE:
	    {
		$$ = remove_current_scope ();
	    }
	    ;

%%

//--------------------------------------------------------------------------

// CODE GENERATION

// Create labels.
char* create_label (void)
{
	char *label = new char[10];
	snprintf(label, 10, "L%d", label_index);
	label_index ++;
	return label;
}

// Create temporary identifiers.
char* create_temporary_identifier (void)
{
	char *temp_id = new char[10];
	snprintf(temp_id, 10, "t%d", temp_id_index);
	temp_id_index ++;
	return temp_id;
}

/* 
    Generate code for statements of type: -
        
           if       A          REL_OP           B    goto    C
        [result] [addr1] RELATIONAL_OPERATOR [addr2] goto [label]
        
    (Conditional Jump)
*/
void generate_code (const char *result, const char *addr1, const char *rel_op, const char *addr2, const char *addr3, int label)
{
    Quadruple q;
    q.result = (char *) result;
    q.addr1 = (char *) addr1;
    q.op = (char *) rel_op;
    q.addr2 = (char *) addr2;
    q.addr3 = (char *) addr3;
    q.label = label;
    quadruples.push_back (q);
    next_instruction_index ++;
}

/* 
    Generate code for statements of type: -
        
           A      =      B       BIN_OP          C
        [result]  =   [addr1] BINARY_OPERATOR [addr2] 
    
    (Binary Assignment Statement)
*/
void generate_code (const char *result, const char *addr1, const char *bin_op, const char *addr2)
{
    generate_code (result, addr1, bin_op, addr2, NULL, 0);
}

/* 
    Generate code for statements of type: -
        
           A      =              UN_OP          C
        [result]  =   [addr1] UNARY_OPERATOR [addr2] 
    
    (Unary Assignment Statement)
*/
void generate_code (const char *result, const char *un_op, const char *addr1)
{
    generate_code (result, NULL, un_op, addr1, NULL, 0);
}

/* 
    Generate code for statements of types: -
        
    1.      A     =      B
        [result]  =   [addr1]
    
    (Simple Assignment Statement)
    
    2.    READ       B
        [result]  [addr1]
    
    (Read Statement)
    
    3.   WRITE       B
        [result]  [addr1]
        
    (Write Statement)
*/
void generate_code (const char *result, const char *addr1)
{
    generate_code (result, addr1, NULL, NULL, NULL, 0);
}

/* 
    Generate code for statements of type: -

          goto      A
        [result] [addr1] 
    
    (Unconditional Jump)
*/
void generate_code (const char *result, int label)
{
    generate_code (result, NULL, NULL, NULL, NULL, label);
}

/* 
    Generate code for statement of type: -

      end of program
        [result]
    
    (End of Program)
*/
void generate_code (const char *result)
{
    generate_code (result, NULL, NULL, NULL, NULL, 0);
}

// Associate labels with backpatched instructions.
void associate_labels (void)
{
    for (int instruction : destination_instructions)
    {
	char *label = create_label ();
	labels.insert (make_pair (instruction, label));
    }
}

// Write the intermediate code to a file.
void write_intermediate_code (void)
{	
    associate_labels ();

    for (int i = 0; i < next_instruction_index; i++)
    {
	// Instruction No.
	fprintf(yyout, "%.4d: ", i);

	// Check if labelled.
	if (labels.find(i) != labels.end())
	{
	    fprintf(yyout, "%s: ", labels[i]);
	}

	// End of Program
	if (strcmp (quadruples[i].result, "end of program") == 0)
        {
            fprintf(yyout, "%s\n", quadruples[i].result);
        }

	// Conditional Jump Statement
        else if (strcmp (quadruples[i].result, "if") == 0)
        {
            fprintf(yyout, "%s %s %s %s %s %s\n",
                    quadruples[i].result, quadruples[i].addr1, quadruples[i].op, 
                    quadruples[i].addr2, quadruples[i].addr3, labels[quadruples[i].label]);
        }

        // Unconditional Jump Statement
        else if (strcmp (quadruples[i].result, "goto") == 0)
        {
            fprintf(yyout, "%s %s\n",
                    quadruples[i].result, labels[quadruples[i].label]);
        }

        // Assignment Statements
	else
	{
	    // Read and Write Assignment Statements
	    if (strcmp (quadruples[i].result, "read") == 0
	        || strcmp (quadruples[i].result, "write") == 0)
	    {
	        fprintf(yyout, "%s %s\n",
                        quadruples[i].result, quadruples[i].addr1);
	    }

            // Unary Assignment Statement
            else if (quadruples[i].addr1 == NULL)
            {
                fprintf(yyout, "%s := %s %s\n",
                        quadruples[i].result, quadruples[i].op, quadruples[i].addr2);
            }

            // Binary Assignment Statement
            else if (quadruples[i].addr2 != NULL)
            {
                fprintf(yyout, "%s := %s %s %s\n",
                        quadruples[i].result, quadruples[i].addr1,
                        quadruples[i].op, quadruples[i].addr2);
            }

            // Simple Assignment Statement
            else
            {
                fprintf(yyout, "%s := %s\n",
                        quadruples[i].result, quadruples[i].addr1);
            }
	}
    }
}

//--------------------------------------------------------------------------

// Backpatching Lists.

vector <int> makeList (int instruction_index)
{
    vector <int> list;
    list.push_back (instruction_index);
    return list;
}

vector <int> mergeLists (vector <int> &list1, vector <int> &list2) 
{
    vector <int> list (list1.size() + list2.size());
    list.insert (list.end(), list1.begin(), list1.end());
    list.insert (list.end(), list2.begin(), list2.end());
    return list;
}
    
void backpatch (vector <int> &list, int instruction_index) 
{
    if (list.size() > 0)
    {
	destination_instructions.insert (instruction_index);
    }

    for (auto index : list)
    {
        quadruples[index].label = instruction_index;
    }
}

//--------------------------------------------------------------------------

//Error Handling.

// Add error to the list of errors.
void add_error (const char *msg, int l_no)
{
    Error e;
    e.error_message =  new char [strlen(msg)];
    strcpy(e.error_message, msg);
    e.line_no = l_no;
    errors.push_back (e);
}

// Write the errors to a file.
void write_errors (void)
{   
    for (Error e : errors)
    {
        fprintf (yyout, "error::line %d: %s\n", e.line_no, e.error_message);
    }
}

//---------------------------------------------------------------------------

// Symbol Table Utilities

int add_new_scope (void)
{
    scope_no ++;
    active_scopes.push_back (scope_no);
    vector <string> identifier;
    identifiers.push_back (identifier);
    return scope_no;
}

int remove_current_scope (void)
{
    int current_scope = active_scopes.back ();
    active_scopes.pop_back ();
    for (string identifier : identifiers[current_scope])
    {
	symbol_table.push_back (make_pair (identifier, make_pair(active_identifiers[identifier], yylineno)));
	active_identifiers.erase (identifier);
    }
    return current_scope;
}

void insert_identifier (char *id, int line_no)
{
    int current_scope = active_scopes.back ();
    string identifier (id, find(id, id + 128, '\0'));
    active_identifiers.insert (make_pair (identifier, line_no));
    identifiers[current_scope].push_back (identifier);
}

bool value_comparator (pair <string, pair <int, int> > &entry1, pair <string, pair <int, int> > &entry2) 
{
    return entry1.second < entry2.second; 
} 

void write_symbol_table (void)
{   
    fprintf (symbol_table_file, "Identifier Name\t\t|\tDeclared At Line No.\t|\tRemoved At Line No.\n");
    fprintf (symbol_table_file, "------------------------------------------------------------------------------------\n");

    // Sort the table in non-increasing order of declaration line nos. of the identifiers.
    sort (symbol_table.begin(), symbol_table.end(), value_comparator);
    
    for (pair <string, pair <int, int> > entry : symbol_table)
    {
        fprintf (symbol_table_file, "\t%s\t\t|\t\t%d\t\t|\t\t%d\n", entry.first.data(), (int)entry.second.first, (int)entry.second.second);
    }
}

//-----------------------------------------------------------------------

void yyerror(const char *s)
{
    add_error (s, yylineno);
}

int main (int argc, char *argv[])
{
    symbol_table_file = NULL;

    if (argc < 3)
    {
        fprintf(stderr, "I/O files not found...\n");
        return 0;
    }
    if (argc > 4)
    {
        fprintf(stderr, "Too many arguments...\n");
        return 0;
    }
    
    yyin = fopen (argv[1],"r");
    yyout = fopen (argv[2], "w");
    
    if (yyin == NULL || yyout == NULL)
    {
        fprintf(stderr, "Error opening file(s)...\n");
        return 0;
    }

    while (!feof(yyin))
    {
        yyparse();
    }

    if(errors.size() == 0)
    {
        write_intermediate_code ();
       	if (argc == 4)
	{
	    symbol_table_file = fopen (argv[3], "w");
            if (symbol_table_file == NULL)
    	    {
        	fprintf(stderr, "Error opening symbol table file...\n");
        	return 0;
    	    }
	    write_symbol_table ();
	    fclose (symbol_table_file);
	}
    }
    else
    {
        write_errors ();
    }

    fclose (yyin);
    fclose (yyout);
    
    return 0;
}