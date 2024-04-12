FLEX = flex
BISON = bison
CC = gcc
CFLAGS = 

PROGRAMA = regalloc
LEXICO = lexico.l
SINTATICO = sintatico.y

OBJS =

$(PROGRAMA): $(OBJS) $(LEXICO) $(SINTATICO) 
	$(FLEX) -o lex.yy.c $(LEXICO)
	$(BISON) -o sintatico.tab.c -d $(SINTATICO) 
	$(CC) -g *.c $(CFLAGS) -o $(PROGRAMA)

clear:
	rm -f sintatico.tab.c
	rm -f lex.yy.c
	rm -f $(PROGRAMA)
	rm -f *.o