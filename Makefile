LEX= flex
YACC= bison
LIBES= -lfl -lm
CXXFLAGS= -w
YFLAGS = -Wno
CC = g++

tinylt: lexer.l parser.y
	$(YACC) -o parser_converted.c -d parser.y $(YFLAGS)
	$(LEX) -o lexer_converted.c lexer.l
	$(CC) -o tinylt parser_converted.c lexer_converted.c $(LIBES) $(CXXFLAGS)