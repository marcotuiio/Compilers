FLEX = flex
BISON = bison
CC = gcc
CFLAGS_BISON = -Wno-unused-function
CFLAGS = -Wall

PROGRAMA = dcmat
LEXICO = lexico.l
SINTATICO = sintatico.y

OBJS = ast.o hash.o

$(PROGRAMA): $(OBJS) $(LEXICO) $(SINTATICO)
	$(FLEX) -o lex.yy.c $(LEXICO)
	$(BISON) -o sintatico.tab.c -d $(SINTATICO)
	$(CC) -g *.c $(CFLAGS_BISON) -o $(PROGRAMA) -lm

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