FLEX = flex
BISON = bison
CC = gcc
CFLAGS = 

PROGRAMA = regalloc
LEXICO = lexico.l
SINTATICO = sintatico.y

OBJS = stack.o graph.o

$(PROGRAMA): $(OBJS) $(LEXICO) $(SINTATICO) 
	$(FLEX) -o lex.yy.c $(LEXICO)
	$(BISON) -o sintatico.tab.c -d $(SINTATICO) 
	$(CC) -g *.c $(CFLAGS) -o $(PROGRAMA) -lm

stack.o: stack.c stack.h
	$(CC) -c stack.c $(CFLAGS)

graph.o: graph.c graph.h
	$(CC) -c graph.c $(CFLAGS)

clear:
	rm -f sintatico.tab.c
	rm -f lex.yy.c
	rm -f $(PROGRAMA)
	rm -f *.o