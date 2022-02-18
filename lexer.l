%{
    #include "parser_converted.h"
    #include <bits/stdc++.h>
    using namespace std;
    extern void add_error (const char *msg, int line_no);
    #define INIT_ID(var) {var = new char[strlen(yytext)]; strcpy(var, yytext);}
%}

%option yylineno

digit   [0-9]
digits  {digit}+
alpha   [a-zA-Z]
id      {alpha}({alpha}|{digit})*
integer {digits}

%%

"{"[^}]*"}"     { /*remove comments*/ }

if          	{ return IF;	  }
then          	{ return THEN; 	  }
else          	{ return ELSE;    }
end          	{ return END; 	  }
repeat        	{ return REPEAT;  }
until         	{ return UNTIL;   }

read          	{ return READ;	  }
write         	{ return WRITE;	  }

":=" 		{ return ASSIGN;  }

"+" 		{ return PLUS;    }
"-"            	{ return MINUS;   }
"*"  		{ return TIMES;   }
"/"            	{ return DIVIDE;  }
"%"            	{ return MODULO;  }

"==" 	 	{ return EQUAL;         }
"<"  		{ return LESS_THAN;     }
">"            	{ return GREATER_THAN;  }

"("            	{ return  LEFT_PAREN; 	}
")"            	{ return  RIGHT_PAREN; 	}
";"            	{ return  SEMICOLON; 	}

{integer}       { INIT_ID (yylval.constantType.addr); return INTEGER_CONSTANT; 	}
{id}            { INIT_ID (yylval.identifierType.addr); return IDENTIFIER; 	}


[\r\t\f\v ]+    { /*remove white spaces*/ }

\n          	{ /*newline*/ }

.		{ add_error ("syntax error", yylineno); }

%%