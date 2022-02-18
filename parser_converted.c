/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

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

#line 154 "parser_converted.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser_converted.h".  */
#ifndef YY_YY_PARSER_CONVERTED_H_INCLUDED
# define YY_YY_PARSER_CONVERTED_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 90 "parser.y" /* yacc.c:355  */

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

#line 211 "parser_converted.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INTEGER_CONSTANT = 258,
    IDENTIFIER = 259,
    IF = 260,
    THEN = 261,
    ELSE = 262,
    END = 263,
    REPEAT = 264,
    UNTIL = 265,
    READ = 266,
    WRITE = 267,
    ASSIGN = 268,
    PLUS = 269,
    MINUS = 270,
    TIMES = 271,
    DIVIDE = 272,
    MODULO = 273,
    LESS_THAN = 274,
    GREATER_THAN = 275,
    EQUAL = 276,
    LEFT_PAREN = 277,
    RIGHT_PAREN = 278,
    SEMICOLON = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 117 "parser.y" /* yacc.c:355  */

    List statementType;
    Primary arithmeticExpressionType;
    DecisionTree booleanExpressionType;
    Primary identifierType;
    Primary constantType;
    Primary operatorType;
    NextInstruction markerMType;
    List markerNType;
    int scope;

#line 260 "parser_converted.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_CONVERTED_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 277 "parser_converted.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   68

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  36
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  73

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   157,   157,   165,   170,   177,   181,   185,   189,   196,
     209,   222,   235,   240,   247,   252,   259,   264,   271,   280,
     284,   291,   295,   302,   306,   310,   317,   323,   332,   341,
     353,   357,   361,   368,   374,   382,   389
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INTEGER_CONSTANT", "IDENTIFIER", "IF",
  "THEN", "ELSE", "END", "REPEAT", "UNTIL", "READ", "WRITE", "ASSIGN",
  "PLUS", "MINUS", "TIMES", "DIVIDE", "MODULO", "LESS_THAN",
  "GREATER_THAN", "EQUAL", "LEFT_PAREN", "RIGHT_PAREN", "SEMICOLON",
  "$accept", "program", "statement_list", "statement", "read_statement",
  "write_statement", "assignment_statement", "arithmetic_expression",
  "multiplicative_expression", "unary_expression", "primary_expression",
  "ARITHOP", "MULOP", "conditional_statement", "boolean_expression",
  "RELOP", "marker_m", "marker_n", "ADD_SCOPE", "REM_SCOPE", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279
};
# endif

#define YYPACT_NINF -41

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-41)))

#define YYTABLE_NINF -37

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -41,     9,    30,   -41,    -2,     3,   -41,    16,    22,   -41,
     -41,   -41,   -41,   -41,   -41,     3,   -41,   -41,   -41,   -41,
       3,    29,    35,   -41,   -41,     3,    34,   -41,     4,    21,
      30,     7,     0,   -41,   -41,   -41,     3,     3,   -41,   -41,
     -41,     3,   -41,   -41,    30,   -41,   -41,   -41,   -41,   -41,
     -41,    35,    40,   -41,   -41,    48,    30,    30,    52,    49,
       3,   -41,    51,    39,    57,   -41,   -41,   -41,   -41,    30,
      58,    59,   -41
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      35,     0,     0,     1,     0,     0,    35,     0,     0,    33,
       4,     5,     6,     7,     8,     0,    19,    18,    21,    22,
       0,     0,    13,    15,    17,     0,     0,    33,     0,     0,
      36,     0,     0,    30,    31,    32,     0,     0,    23,    24,
      25,     0,    16,    35,     0,     9,    10,     3,     2,    11,
      20,    12,    29,    14,    33,    33,     0,     0,     0,    33,
       0,    36,     0,     0,     0,    26,    28,    35,    33,     0,
      33,     0,    27
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -41,   -41,   -40,   -27,   -41,   -41,   -41,   -10,    32,   -17,
     -41,   -19,   -41,   -41,     5,   -41,    -8,   -41,    -6,   -23
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     9,    10,    11,    12,    13,    21,    22,    23,
      24,    25,    41,    14,    26,    37,    57,    61,     2,    48
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      27,    30,    36,    47,    55,    31,    16,    17,    42,     3,
      32,    15,    36,    36,    18,    19,    59,    18,    19,    44,
      28,    18,    19,    50,    53,    20,    29,    52,    45,    70,
      47,    49,    58,    36,     4,     5,    62,    54,    64,     6,
      43,     7,     8,    18,    19,    46,    56,    71,    33,    34,
      35,    38,    39,    40,    18,    19,   -34,   -36,   -36,    65,
      69,    68,    60,    66,    67,    63,   -36,    72,    51
};

static const yytype_uint8 yycheck[] =
{
       6,     9,    21,    30,    44,    15,     3,     4,    25,     0,
      20,    13,    31,    32,    14,    15,    56,    14,    15,    27,
       4,    14,    15,    23,    41,    22,     4,    37,    24,    69,
      57,    24,    55,    52,     4,     5,    59,    43,    61,     9,
       6,    11,    12,    14,    15,    24,    54,    70,    19,    20,
      21,    16,    17,    18,    14,    15,     7,     8,    10,     8,
      68,    67,    10,    24,     7,    60,     8,     8,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,    43,     0,     4,     5,     9,    11,    12,    27,
      28,    29,    30,    31,    38,    13,     3,     4,    14,    15,
      22,    32,    33,    34,    35,    36,    39,    43,     4,     4,
      41,    32,    32,    19,    20,    21,    36,    40,    16,    17,
      18,    37,    34,     6,    41,    24,    24,    28,    44,    24,
      23,    33,    32,    34,    43,    27,    41,    41,    44,    27,
      10,    42,    44,    39,    44,     8,    24,     7,    43,    41,
      27,    44,     8
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    25,    26,    27,    27,    28,    28,    28,    28,    29,
      30,    31,    32,    32,    33,    33,    34,    34,    35,    35,
      35,    36,    36,    37,    37,    37,    38,    38,    38,    39,
      40,    40,    40,    41,    42,    43,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     3,     1,     1,     1,     1,     1,     3,
       3,     4,     3,     1,     3,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     8,    14,     8,     3,
       1,     1,     1,     0,     0,     0,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 158 "parser.y" /* yacc.c:1646  */
    {
	    backpatch (*((yyvsp[-2].statementType).nextList), (yyvsp[-1].markerMType).nextIns);
	    generate_code ("end of program");
	}
#line 1400 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 3:
#line 166 "parser.y" /* yacc.c:1646  */
    {
                    backpatch (*((yyvsp[-2].statementType).nextList), (yyvsp[-1].markerMType).nextIns);
                    *((yyval.statementType).nextList) = *((yyvsp[0].statementType).nextList);
                }
#line 1409 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 4:
#line 171 "parser.y" /* yacc.c:1646  */
    {
		    *((yyval.statementType).nextList) = *((yyvsp[0].statementType).nextList);
		}
#line 1417 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 5:
#line 178 "parser.y" /* yacc.c:1646  */
    {
                *((yyval.statementType).nextList) = *((yyvsp[0].statementType).nextList);
            }
#line 1425 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 6:
#line 182 "parser.y" /* yacc.c:1646  */
    {
                *((yyval.statementType).nextList) = *((yyvsp[0].statementType).nextList);
            }
#line 1433 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 7:
#line 186 "parser.y" /* yacc.c:1646  */
    {
                *((yyval.statementType).nextList) = *((yyvsp[0].statementType).nextList);
            }
#line 1441 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 8:
#line 190 "parser.y" /* yacc.c:1646  */
    {
                *((yyval.statementType).nextList) = *((yyvsp[0].statementType).nextList);
            }
#line 1449 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 9:
#line 197 "parser.y" /* yacc.c:1646  */
    {
		    (yyval.statementType).nextList = new vector <int> ();
    		    string identifier ((yyvsp[-1].identifierType).addr, find((yyvsp[-1].identifierType).addr, (yyvsp[-1].identifierType).addr + 128, '\0'));
                    if (active_identifiers.find(identifier) == active_identifiers.end())
		    {
			insert_identifier ((yyvsp[-1].identifierType).addr, yylineno);
		    }
                    generate_code ("read", (yyvsp[-1].identifierType).addr);
                }
#line 1463 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 10:
#line 210 "parser.y" /* yacc.c:1646  */
    {
		    (yyval.statementType).nextList = new vector <int> ();
    		    string identifier ((yyvsp[-1].identifierType).addr, find((yyvsp[-1].identifierType).addr, (yyvsp[-1].identifierType).addr + 128, '\0'));
                    if (active_identifiers.find(identifier) == active_identifiers.end())
                    {
			add_error (string{"variable '" + identifier + "' not declared in current scope"}.data(), yylineno);
                    }
		    generate_code ("write", (yyvsp[-1].identifierType).addr);
                }
#line 1477 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 11:
#line 223 "parser.y" /* yacc.c:1646  */
    {
			    (yyval.statementType).nextList = new vector <int> ();
			    string identifier ((yyvsp[-3].identifierType).addr, find((yyvsp[-3].identifierType).addr, (yyvsp[-3].identifierType).addr + 128, '\0'));
                    	    if (active_identifiers.find(identifier) == active_identifiers.end())
                    	    {
				insert_identifier ((yyvsp[-3].identifierType).addr, yylineno);
                    	    }
                            generate_code ((yyvsp[-3].identifierType).addr, (yyvsp[-1].arithmeticExpressionType).addr);
                        }
#line 1491 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 12:
#line 236 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.arithmeticExpressionType).addr = create_temporary_identifier ();
                            generate_code ((yyval.arithmeticExpressionType).addr, (yyvsp[-2].arithmeticExpressionType).addr, (yyvsp[-1].operatorType).addr, (yyvsp[0].arithmeticExpressionType).addr);
                        }
#line 1500 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 13:
#line 241 "parser.y" /* yacc.c:1646  */
    {
                            (yyval.arithmeticExpressionType).addr = (yyvsp[0].arithmeticExpressionType).addr;
                        }
#line 1508 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 14:
#line 248 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.arithmeticExpressionType).addr = create_temporary_identifier ();
                                generate_code ((yyval.arithmeticExpressionType).addr, (yyvsp[-2].arithmeticExpressionType).addr, (yyvsp[-1].operatorType).addr, (yyvsp[0].arithmeticExpressionType).addr);
                            }
#line 1517 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 15:
#line 253 "parser.y" /* yacc.c:1646  */
    {
                                (yyval.arithmeticExpressionType).addr = (yyvsp[0].arithmeticExpressionType).addr;
                            }
#line 1525 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 16:
#line 260 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.arithmeticExpressionType).addr = create_temporary_identifier ();
                        generate_code ((yyval.arithmeticExpressionType).addr, (yyvsp[-1].operatorType).addr, (yyvsp[0].arithmeticExpressionType).addr);
                    }
#line 1534 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 17:
#line 265 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.arithmeticExpressionType).addr = (yyvsp[0].arithmeticExpressionType).addr;
                    }
#line 1542 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 18:
#line 272 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.arithmeticExpressionType).addr = (yyvsp[0].identifierType).addr;
			string identifier ((yyvsp[0].identifierType).addr, find((yyvsp[0].identifierType).addr, (yyvsp[0].identifierType).addr + 128, '\0'));
                        if (active_identifiers.find(identifier) == active_identifiers.end())
                        {
			    add_error (string{"variable '" + identifier + "' not declared in current scope"}.data(), yylineno);
                        }
                    }
#line 1555 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 19:
#line 281 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.arithmeticExpressionType).addr = (yyvsp[0].constantType).addr;
                    }
#line 1563 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 20:
#line 285 "parser.y" /* yacc.c:1646  */
    {
                        (yyval.arithmeticExpressionType).addr = (yyvsp[-1].arithmeticExpressionType).addr;    
                    }
#line 1571 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 21:
#line 292 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "+";
        }
#line 1579 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 22:
#line 296 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "-";
        }
#line 1587 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 23:
#line 303 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "*";
        }
#line 1595 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 24:
#line 307 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "/";
        }
#line 1603 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 25:
#line 311 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "%";
        }
#line 1611 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 26:
#line 318 "parser.y" /* yacc.c:1646  */
    {
			    (yyval.statementType).nextList = new vector <int> ();
                            backpatch (*((yyvsp[-6].booleanExpressionType).trueList), (yyvsp[-3].markerMType).nextIns);
                            *((yyval.statementType).nextList) = mergeLists (*((yyvsp[-6].booleanExpressionType).falseList), *((yyvsp[-2].statementType).nextList));
                        }
#line 1621 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 27:
#line 325 "parser.y" /* yacc.c:1646  */
    {
			    (yyval.statementType).nextList = new vector <int> ();
                            backpatch (*((yyvsp[-12].booleanExpressionType).trueList), (yyvsp[-9].markerMType).nextIns);
                            backpatch (*((yyvsp[-12].booleanExpressionType).falseList), (yyvsp[-3].markerMType).nextIns);
                            vector <int> temp = mergeLists (*((yyvsp[-8].statementType).nextList), *((yyvsp[-7].markerNType).nextList));
                            *((yyval.statementType).nextList) = mergeLists (temp, *((yyvsp[-2].statementType).nextList));
                        }
#line 1633 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 28:
#line 333 "parser.y" /* yacc.c:1646  */
    {
			    (yyval.statementType).nextList = new vector <int> ();
                            backpatch (*((yyvsp[-1].booleanExpressionType).falseList), (yyvsp[-5].markerMType).nextIns);
                            *((yyval.statementType).nextList) = mergeLists (*((yyvsp[-4].statementType).nextList), *((yyvsp[-1].booleanExpressionType).trueList));
                        }
#line 1643 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 29:
#line 342 "parser.y" /* yacc.c:1646  */
    {
			(yyval.booleanExpressionType).trueList = new vector <int> ();
			(yyval.booleanExpressionType).falseList = new vector <int> ();
			*((yyval.booleanExpressionType).trueList) = makeList (next_instruction_index);
                        *((yyval.booleanExpressionType).falseList) = makeList (next_instruction_index + 1);
                        generate_code ("if", (yyvsp[-2].arithmeticExpressionType).addr, (yyvsp[-1].operatorType).addr, (yyvsp[0].arithmeticExpressionType).addr, "goto", UNKNOWN);
                        generate_code ("goto", UNKNOWN);
                    }
#line 1656 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 30:
#line 354 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "<";
        }
#line 1664 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 31:
#line 358 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) ">";
        }
#line 1672 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 32:
#line 362 "parser.y" /* yacc.c:1646  */
    {
            (yyval.operatorType).addr = (char *) "==";
        }
#line 1680 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 33:
#line 368 "parser.y" /* yacc.c:1646  */
    {
                (yyval.markerMType).nextIns = next_instruction_index;
            }
#line 1688 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 34:
#line 374 "parser.y" /* yacc.c:1646  */
    {
		(yyval.markerNType).nextList = new vector <int> ();
                *((yyval.markerNType).nextList) = makeList (next_instruction_index);
                generate_code ("goto", UNKNOWN);
            }
#line 1698 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 35:
#line 382 "parser.y" /* yacc.c:1646  */
    {
		(yyval.scope) = add_new_scope ();
	    }
#line 1706 "parser_converted.c" /* yacc.c:1646  */
    break;

  case 36:
#line 389 "parser.y" /* yacc.c:1646  */
    {
		(yyval.scope) = remove_current_scope ();
	    }
#line 1714 "parser_converted.c" /* yacc.c:1646  */
    break;


#line 1718 "parser_converted.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 394 "parser.y" /* yacc.c:1906  */


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
