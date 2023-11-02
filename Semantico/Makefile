FLEX = flex
BISON = bison
CC = gcc
CFLAGS = -Wall
OBJECTS = lexico.l sintatico.y ast.o hash.o

PROGRAMA = semantico
LEXICO = lexico.l
SINTATICO = sintatico.y

$(PROGRAMA): $(OBJECTS)
	$(FLEX) $(LEXICO)
	$(BISON) -d $(SINTATICO)
	$(CC) $(CFLAGS) *.c -I. -o $(PROGRAMA)

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

clear:
	rm -f sintatico.tab.c
	rm -f lex.yy.c
	rm -f $(PROGRAMA)
	rm -f diff.txt
	rm -f *.o