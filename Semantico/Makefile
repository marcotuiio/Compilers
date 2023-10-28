FLEX=flex
BISON=bison
CC=gcc
CFLAGS=-Wall

PROGRAMA = semantico
LEXICO = lexico.l
SINTATICO = sintatico.y

$(PROGRAMA): $(LEXICO) $(SINTATICO) ast.o
	$(FLEX) $(LEXICO)
# $(BISON) -d -Wcounterexamples $(SINTATICO)
	$(BISON) -d $(SINTATICO)
	$(CC) $(CFLAGS) *.c -I. -o $(PROGRAMA)

ast.o: ast.c ast.h
	$(CC) $(CFLAGS) -c ast.c

clear:
	rm -f sintatico.tab.c
# rm -f sintatico.tab.h
	rm -f lex.yy.c
	rm -f $(PROGRAMA)
	rm -f diff.txt
	rm -f *.o