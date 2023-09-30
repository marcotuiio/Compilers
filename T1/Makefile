EXEC = gcc
CFLAGS = -fstack-protector-all -g -Wall
PROJECT_NAME = l10e4
OBJETCS = PORTUGOL_LEXICO.o linked_list.o

clear: 
	rm -f *.o
	rm -f $(PROJECT_NAME)
	rm -f diff.txt

$(PROJECT_NAME): $(OBJETCS)
	$(EXEC) $(CFLAGS) $(OBJETCS) -o $(PROJECT_NAME) -lm

LISTA_9_EXERCICIO_1.o: PORTUGOL_LEXICO.c PORTUGOL_LEXICO.h
	$(EXEC) $(CFLAGS) -c PORTUGOL_LEXICO.c

linked_list.o: linked_list.c linked_list.h
	$(EXEC) $(CFLAGS) -c linked_list.c