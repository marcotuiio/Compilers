#include "ast.h"
#include "sintatico.tab.h"

extern void printLineError(int line, int column);

Program *createProgram(void **hash, void *functionsList, void *main) {
    Program *newProg = calloc(1, sizeof(Program));
    newProg->hashTable = hash;
    newProg->functionsList = functionsList;
    newProg->main = main;
    return newProg;
}

Function *createFunction(void **hash, int returnType, int pointer, char *name, void *commandList, void *next) {
    Function *newFunc = calloc(1, sizeof(Function));
    newFunc->hashTable = hash;
    newFunc->returnType = returnType;
    newFunc->pointer = pointer;
    newFunc->name = name;
    newFunc->commandList = commandList;
    newFunc->next = next;
    return newFunc;
}

Expression *createExpression(int type, int operator, void *aux, void *left, void *right) {
    Expression *newExp = calloc(1, sizeof(Expression));
    newExp->type = type;
    newExp->operator = operator;
    newExp->value = aux;
    newExp->left = left;
    newExp->right = right;
    return newExp;
}

Dimension *createDimension(Expression *size) {
    Dimension *newDim = calloc(1, sizeof(Dimension));
    newDim->size = size;
    return newDim;
}

Command *createIfStatement(Expression *condition, void *then, void *elseStatement, void *next) {
    Command *newIf = calloc(1, sizeof(Command));
    newIf->type = IF;
    newIf->condition = condition;
    newIf->then = then;
    newIf->elseStatement = elseStatement;
    newIf->next = next;
    return newIf;
}

Command *createElseStatement(void *then, void *next) {
    Command *newElse = calloc(1, sizeof(Command));
    newElse->type = ELSE;
    newElse->then = then;
    newElse->next = next;
    return newElse;
}

Command *createDoWhileStatement(Expression *condition, void *then, void *next) {
    Command *newDoWhile = calloc(1, sizeof(Command));
    newDoWhile->type = DO;
    newDoWhile->condition = condition;
    newDoWhile->then = then;
    newDoWhile->next = next;
    return newDoWhile;
}

Command *createWhileStatement(Expression *condition, void *then, void *next) {
    Command *newWhile = calloc(1, sizeof(Command));
    newWhile->type = WHILE;
    newWhile->condition = condition;
    newWhile->then = then;
    newWhile->next = next;
    return newWhile;
}

Command *createForStatement(Expression *init, Expression *condition, Expression *increment, void *then, void *next) {
    Command *newFor = calloc(1, sizeof(Command));
    newFor->type = FOR;
    newFor->init = init;
    newFor->condition = condition;
    newFor->increment = increment;
    newFor->then = then;
    newFor->next = next;
    return newFor;
}

Command *createPrintStatement(char *string, Expression *auxPrint, void *next) {
    Command *newPrint = calloc(1, sizeof(Command));
    newPrint->type = PRINTF;
    newPrint->string = string;
    newPrint->auxPrint = auxPrint;
    newPrint->next = next;
    return newPrint;
}

Command *createScanStatement(char *identifier, char *format, void *next) {
    Command *newScan = calloc(1, sizeof(Command));
    newScan->type = SCANF;
    newScan->identifier = identifier;
    newScan->format = format;
    newScan->next = next;
    return newScan;
}

Command *createReturnStatement(Expression *expression, void *next) {
    Command *newReturn = calloc(1, sizeof(Command));
    newReturn->type = RETURN;
    newReturn->condition = expression;
    newReturn->next = next;
    return newReturn;
}

Command *createExitStatement(Expression *expression, void *next) {
    Command *newExit = calloc(1, sizeof(Command));
    newExit->type = EXIT;
    newExit->condition = expression;
    newExit->next = next;
    return newExit;
}

Command *createCommandExpression(Expression *expression, void *next) {
    Command *newCommand = calloc(1, sizeof(Command));
    newCommand->type = 9802;
    newCommand->condition = expression;
    newCommand->next = next;
    return newCommand;

}
void evalExpression(void *node, void *expression) {
    Expression *exp = expression;
    printf("type: %d\n", exp->type);
    // switch (exp->type) {
   
    // }
    return;
}

void traverseASTExpression(Expression *expression) {
    if (expression == NULL) return;

    printf("Type: %d\n", expression->type);

    switch (expression->type) {
        case ATRIBUICAO:
        case NAOSEI:
        case TERNARY:
        case OR_LOGICO:
        case AND_LOGICO:
        case OR_BIT:
        case XOR_BIT:
        case AND_BIT:
        case IGUALDADE:
        case RELACIONAL:
        case SHIFT:
        case ADITIVIVA:
        case MULTIPLICATIVA:
        case CASTING:
        case UNARIA:
        case POS_FIXA:
        case PRIMARIA:
        case NUMEROS:
            break;
        default:
            printf("Unknown expression type\n");
            break;
    }

    // Recursivamente chame a função para as subexpressões
    if (expression->left != NULL) {
        printf("Left Operand:\n");
        traverseASTExpression(expression->left);
    }

    if (expression->right != NULL) {
        printf("Right Operand:\n");
        traverseASTExpression(expression->right);
    }

    // Você pode adicionar mais casos aqui para tipos específicos, se necessário
}

void traverseASTCommand(Command *command) {
    if (command == NULL) {
        return;
    }

    // Imprima o tipo do comando
    printf("Command Type: %d\n", command->type);

    // Se o comando for um comando de expressão, percorra a expressão
    if (command->type == 9802) {
        traverseASTExpression(command->condition);
    }

    // Se o comando for um comando IF ou ELSE, percorra as condições e blocos
    if (command->type == IF || command->type == ELSE) {
        traverseASTExpression(command->condition);
        traverseASTCommand(command->then);
        traverseASTCommand(command->elseStatement);
    }

    // Se o comando for um comando WHILE ou DO-WHILE, percorra a condição e o bloco
    if (command->type == WHILE || command->type == DO) {
        traverseASTExpression(command->condition);
        traverseASTCommand(command->then);
    }

    // Se o comando for um comando FOR, percorra a inicialização, condição, incremento e bloco
    if (command->type == FOR) {
        traverseASTExpression(command->init);
        traverseASTExpression(command->condition);
        traverseASTExpression(command->increment);
        traverseASTCommand(command->then);
    }

    // Se o comando for um comando PRINTF ou SCANF, percorra os argumentos
    if (command->type == PRINTF || command->type == SCANF) {
        traverseASTExpression(command->auxPrint);
    }

    // Se o comando for um comando RETURN ou EXIT, percorra a expressão
    if (command->type == RETURN || command->type == EXIT) {
        traverseASTExpression(command->condition);
    }

    // Continue percorrendo os comandos na lista
    traverseASTCommand(command->next);
}

int traverseAST(Program *program) {
    if (!program) return -1;

    // Percorra as funções na lista de funções
    Function *currentFunction = program->functionsList;
    while (currentFunction != NULL) {
        printf("Function: %s\n", currentFunction->name);

        // Percorra os comandos na função
        Command *currentCommand = currentFunction->commandList;
        while (currentCommand != NULL) {
            traverseASTCommand(currentCommand);
            currentCommand = currentCommand->next;
        }

        currentFunction = currentFunction->next;
    }
    return 0;
}

// int traverseAST(Program *program) {
//     if (!program) return 0;
//     // traverseHash(program->hashTable);
//     Function *auxFunc = program->functionsList;
//     while (auxFunc) {
//         Command *auxCommand = auxFunc->commandList;
//         switch (auxCommand->type) {
//             case IF:
//                 break;
//             case ELSE:
//                 break;
//             case DO:
//                 break;
//             case WHILE:
//                 break;
//             case FOR:
//                 break;
//             case PRINTF:
//                 break;
//             case SCANF:
//                 break;
//             case RETURN:
//                 break;
//             case EXIT:
//                 break;
//         }
//         auxFunc = auxFunc->next;
//     } 
//     return 0;
// }

void freeAST(Program *program) {
    if (!program) return;
    
    free(program);
}