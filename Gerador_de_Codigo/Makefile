FLEX = flex
BISON = bison
CC = gcc
CFLAGS = 

PROGRAMA = gerador
LEXICO = lexico.l
SINTATICO = sintatico.y

OBJS = ast.o hash.o asm.o

$(PROGRAMA): $(OBJS) $(LEXICO) $(SINTATICO) 
	$(FLEX) -o lex.yy.c $(LEXICO)
	$(BISON) -o sintatico.tab.c -d $(SINTATICO) 
	$(CC) -g *.c $(CFLAGS) -o $(PROGRAMA)

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

hash.o: hash.c hash.h
	$(CC) $(CFLAGS) -c hash.c

asm.o: asm.c asm.h
	$(CC) $(CFLAGS) -c asm.c

clear:
	rm -f sintatico.tab.c
	rm -f lex.yy.c
	rm -f $(PROGRAMA)
	rm -f *.o