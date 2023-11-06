#include "ast.h"

#include "hash.h"
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

Expression *createExpression(int type, int operator, void *value, void *left, void *right) {
    Expression *newExp = calloc(1, sizeof(Expression));
    newExp->type = type;
    newExp->operator= operator;
    newExp->value = value;
    newExp->left = left;
    newExp->right = right;
    newExp->dimension = NULL;
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

int evalExpression(Expression *expr) {
    if (!expr) return -1;
    printf("type: %d\n", expr->type);

    switch (expr->type) {
        case NUMEROS:
            printf("numeros\n");
            return atoi(expr->value);
        
        case ATRIBUICAO:
            // Implementação depende do seu ambiente
            if (expr->operator == ASSIGN) {
                printf("assign %s %s\n", (char *)expr->left->value, (char *)expr->right->value);
            } else if (expr->operator == ADD_ASSIGN) {
                printf("add assign\n");
            } else if (expr->operator == MINUS_ASSIGN) {
                printf("sub assign\n");
            }
            break;
        
        case LISTA_EXP:
            // Implementação depende do seu ambiente
            printf("lista_exp\n");
            break;
        
        case TERNARY:
            if (evalExpression(expr->left)) {
                printf("ternary\n");
                return evalExpression(expr->right->left);
            } else {
                printf("ternary\n");
                return evalExpression(expr->right->right);
            }
        
        case OR_LOGICO:
            printf("or logico\n");
            return evalExpression(expr->left) || evalExpression(expr->right);
        
        case AND_LOGICO:
            printf("and logico\n");
            return evalExpression(expr->left) && evalExpression(expr->right);
        
        case OR_BIT:
            printf("or bit\n");
            return evalExpression(expr->left) | evalExpression(expr->right);
        
        case XOR_BIT:
            printf("xor bit\n");
            return evalExpression(expr->left) ^ evalExpression(expr->right);
        
        case AND_BIT:
            printf("and bit\n");
            return evalExpression(expr->left) & evalExpression(expr->right);
        
        case IGUALDADE:
            if (expr->operator == EQUAL) {
                printf("equal\n");
                return evalExpression(expr->left) == evalExpression(expr->right);
            } else if (expr->operator == NOT_EQUAL) {
                printf("not equal\n");
                return evalExpression(expr->left) != evalExpression(expr->right);
            }
            break;
        
        case RELACIONAL:
            // Implementação depende do seu ambiente
            printf("relacional\n");
            break;
        
        case SHIFT:
            // Implementação depende do seu ambiente
            printf("shift\n");
            break;
        
        case ADITIVIVA:
            if (expr->operator == PLUS) {
                printf("plus\n");
                return evalExpression(expr->left) + evalExpression(expr->right);
            } else if (expr->operator == MINUS) {
                printf("minus\n");  
                return evalExpression(expr->left) - evalExpression(expr->right);
            }
            break;
        
        case MULTIPLICATIVA:
            if (expr->operator == MULTIPLY) {
                printf("multiply\n");
                return evalExpression(expr->left) * evalExpression(expr->right);
            } else if (expr->operator == DIVIDE) {
                printf("divide\n");
                return evalExpression(expr->left) / evalExpression(expr->right);
            } else if (expr->operator == REMAINDER) {
                printf("remainder\n");
                return evalExpression(expr->left) % evalExpression(expr->right);
            }
            break;
        
        case CASTING:
            // Implementação depende do seu ambiente
            printf("casting\n");
            break;
        
        case UNARIA:
            if (expr->operator == BITWISE_NOT) {
                printf("bitwise not\n");
                return ~evalExpression(expr->left);
            } else if (expr->operator == NOT) {
                printf("not\n");
                return !evalExpression(expr->left);
            }
            // Outros operadores unários
            break;

        case POS_FIXA:
            printf("pos fixa\n");
            // Implementação depende do seu ambiente
            break;
        
        case PRIMARIA:
            printf("primaria\n");
            // Implementação depende do seu ambiente
            break;
        
        default:
            printf("Tipo de expressão não suportado\n");
            return 0;
    }
    return 0;
}

void traverseASTExpression(Expression *expression) {
    if (expression == NULL) return;

    switch (expression->type) {
        case ATRIBUICAO:
            printf("Type ATRIBUICAO\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case LISTA_EXP:  // Expressao COMMA ExpressaoAtribuicao
            printf("Type LISTA_EXP\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case TERNARY:
            printf("Type TERNARY\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case OR_LOGICO:
            printf("Type OR_LOGICO\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case AND_LOGICO:
            printf("Type AND_LOGICO\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case OR_BIT:
            printf("Type OR_BIT\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case XOR_BIT:
            printf("Type XOR_BIT\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case AND_BIT:
            printf("Type AND_BIT\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case IGUALDADE:
            printf("Type IGUALDADE\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case RELACIONAL:
            printf("Type RELACIONAL\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case SHIFT:
            printf("Type SHIFT\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case ADITIVIVA:
            printf("Type ADITIVIVA\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case MULTIPLICATIVA:
            printf("Type MULTIPLICATIVA\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case CASTING:
            printf("Type CASTING\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case UNARIA:
            printf("Type UNARIA\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case POS_FIXA:
            printf("Type POS_FIXA\n");
            printf("Operator: %d\n", expression->operator);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);  // 1
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);  // 2
            break;

        case PRIMARIA:
            printf("Type PRIMARIA\n");
            printf("Operator: %d %s\n", expression->operator,(char *) expression->value);
            printf("Left Operand:\n");
            traverseASTExpression(expression->left);
            printf("Right Operand:\n");
            traverseASTExpression(expression->right);
            break;

        case NUMEROS:
            printf("Type NUMEROS\n");
            printf("Value: %s %d\n", (char *)expression->value, (int)expression->posIncrement);
            break;

        default:
            printf("Unknown expression type: %p \n", expression);
            break;
    }
}

void traverseASTCommand(Command *command) {
    if (command == NULL) return;

    // Se o comando for um comando de expressão, percorra a expressão
    if (command->type == 9802) {
        printf("Command de expressão\n");
        evalExpression(command->condition);
    }

    // Se o comando for um comando IF ou ELSE, percorra as condições e blocos
    if (command->type == IF || command->type == ELSE) {
        printf("Command de if ou else\n");
        evalExpression(command->condition);
        traverseASTCommand(command->then);
        traverseASTCommand(command->elseStatement);
    }

    // Se o comando for um comando WHILE ou DO-WHILE, percorra a condição e o bloco
    if (command->type == WHILE || command->type == DO) {
        printf("Command de while ou do-while\n");
        evalExpression(command->condition);
        traverseASTCommand(command->then);
    }

    // Se o comando for um comando FOR, percorra a inicialização, condição, incremento e bloco
    if (command->type == FOR) {
        printf("Command de for\n");
        evalExpression(command->init);
        evalExpression(command->condition);
        evalExpression(command->increment);
        traverseASTCommand(command->then);
    }

    // Se o comando for um comando PRINTF ou SCANF, percorra os argumentos
    if (command->type == PRINTF || command->type == SCANF) {
        printf("Command de printf ou scanf\n");
        evalExpression(command->auxPrint);
    }

    // Se o comando for um comando RETURN ou EXIT, percorra a expressão
    if (command->type == RETURN || command->type == EXIT) {
        printf("Command de return ou exit\n");
        if (command->condition) evalExpression(command->condition);
    }

    // Continue percorrendo os comandos na lista
    // traverseASTCommand(command->next);
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

// void freeExpressions(Expression *expression) {
//     if (!expression) return;

//     if (expression->dimension) {
//         Dimension *dim = expression->dimension;
//         while (dim) {
//             Dimension *dim2 = dim->next;
//             if (dim->size) free(dim->size);
//             free(dim);
//             dim = dim2;
//         }
//     }
//     if (expression->extra) free(expression->extra);
//     if (expression->ternary) free(expression->ternary);
//     if (expression->value) free(expression->value);

//     Expression *left = expression->left;
//     Expression *right = expression->right;

//     free(expression);

//     freeExpressions(left);
//     freeExpressions(right);
// }

void freeAST(Program *program) {
    if (!program) return;
    freeHash(program->hashTable);

    Function *functions = program->functionsList;
    while (functions) {
        Function *functions2 = functions->next;
        Command *cmd = functions->commandList;
        while (cmd) {
            Command *cmd2 = cmd->next;
            if (cmd->condition) free(cmd->condition);
            if (cmd->init) free(cmd->init);
            if (cmd->increment) free(cmd->increment);
            if (cmd->auxPrint) free(cmd->auxPrint);
            free(cmd);
            cmd = cmd2;
        }
        freeHash(functions->hashTable);
        if (functions->name) free(functions->name);
        free(functions);
        functions = functions2;
    }
    free(program);
}