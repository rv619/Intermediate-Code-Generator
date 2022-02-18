# Intermediate-Code-Generator
The Intermediate Code Generator that will take a piece of code written in TINYLT langugae and generate intermediate code in quadruple notation.

# Features of the TINYLT Language 
1. A program is a sequence of statements terminated by a semicolon (‘;’).
2. There are no procedures (functions), structures, libraries, or arrays.
3. All variables are of integer type.
4. There are no separate declaration statements. Whenever a variable gets assigned, it
gets declared (that is, inserted into the symbol table). A variable cannot be used unless
declared. The assignment operator is ‘:=’.
5. A variable can only be used within the scope in which it is declared. There is no concept
of local and global variables. The idea of “scope” of a variable is similar to C language.
6. Another way to declare (or read) a variable is by using the statement “read <variable
name>”.
7. A variable can be printed using the statement “write <variable name>”.
8. There are 3 types of flow control statements: -<br />
—> if condition then statements end<br />
—> if condition then statements else statements end<br />
—> repeat statements until condition<br />
“condition” can be only boolean expression type.
9. Arithmetic exprsessions can be on integer constants, variables, or parenthesis. Arith-
metic operators are ‘+’,‘-’,‘*’,‘/’,‘%’ (as in C language).
10. Boolean expressions can be on two arithmetic expressions connected via a logical op-
erator. Logical operators are ‘<’, ‘>’, ‘==’ (as in C language). There is no concept of
boolean variables.
11. Comments are within “{....}” and cannot be nested. However, both single-line and
multi-line comments are allowed.

# Files
It contains two main source files: -<br /><br />
  lexer.l - flex source file.<br />
  parser.y - bison source file.
<br /><br />Both the flex and bison files are self-explanatory and well-commented.<br /><br />
The other files include Makefile, auto-generated files (.c and .h files by flex and bison), test files (.tnlt files), and files containing test results (.ic and .symt files).<br /><br />
TINYLT source file (.tnlt) – It contains the source code.<br />
Intermediate code file (.ic) – It contains the intermediate code in the form of quadruples when there are no errors in the TINYLT source file. In case of one or more errors, this file contains the details of those errors (error message along with the line number).<br />
Symbol table file (.symt) – It contains the symbol table (variable name, variable declaration line no., variable removal line no.). This file is created only when there are no errors in the TINYLT source file.

# Running the ICG: -
The ICG can be run using either of the following two commands: -<br />
./tinylt \<TINYLT source file\> \<intermediate code file\><br />
./tinylt \<TINYLT source file\> \<intermediate code file\> \<symbol table file\><br /><br />
Just for the sake of convention, we will be using the extension .tnlt for the TINYLT source files, .ic for the intermediate code files, and .symt for the symbol table files.
