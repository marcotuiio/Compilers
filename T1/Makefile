# Author: Marco Túlio Alves de Barros

EXEC = gcc
CFLAGS = -fstack-protector-all -g -Wall
PROJECT_NAME = portugol
OBJETCS = PORTUGOL_LEXICO.o PORTUGOL_SINTATICO.o linked_list.o

clear: 
	rm -f *.o
	rm -f $(PROJECT_NAME)
	rm -f diff.txt

$(PROJECT_NAME): $(OBJETCS)
	$(EXEC) $(CFLAGS) $(OBJETCS) -o $(PROJECT_NAME) -lm

PORTUGOL_LEXICO.o: PORTUGOL_LEXICO.c PORTUGOL_LEXICO.h
	$(EXEC) $(CFLAGS) -c PORTUGOL_LEXICO.c

PORTUGOL_SINTATICO.o: PORTUGOL_SINTATICO.c PORTUGOL_SINTATICO.h
	$(EXEC) $(CFLAGS) -c PORTUGOL_SINTATICO.c

linked_list.o: linked_list.c linked_list.h
	$(EXEC) $(CFLAGS) -c linked_list.c