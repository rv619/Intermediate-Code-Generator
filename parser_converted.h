/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 90 "parser.y" /* yacc.c:1909  */

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

#line 71 "parser_converted.h" /* yacc.c:1909  */

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
#line 117 "parser.y" /* yacc.c:1909  */

    List statementType;
    Primary arithmeticExpressionType;
    DecisionTree booleanExpressionType;
    Primary identifierType;
    Primary constantType;
    Primary operatorType;
    NextInstruction markerMType;
    List markerNType;
    int scope;

#line 120 "parser_converted.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_CONVERTED_H_INCLUDED  */
