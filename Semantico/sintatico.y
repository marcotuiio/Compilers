%{
#include "ast.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

extern int yylex();
void yyerror(void *s);

extern int yychar;
extern int textBefore;
extern char lineBuffer[2048];
extern void getLineBuffer();

extern char wrongToken[32];
extern int wrongTokenLine;
extern int wrongTokenColumn;

int erroAux = 0;
int semanticError = 0;
int CURRENT_TYPE, AUX_CURRENT_TYPE = -1;
int paramsQntd = 0;
int auxPosIncrement;

void *prototypeParam = NULL;


void **globalHash = NULL;
void **currentHash = NULL;

Program *AST = NULL;

void printLineError(int line, int column);

%}

%union {
    Program *prog;
    Function *func;
    Dimension *dim;
    Expression *expr;
    Command *cmd;
    void *param;
    int ptr;
    struct {
        char *valor;
        int column;
        int line;
        int type;
    } token;
}

%token MyEOF
%token ERRO

%token NUMBER_SIGN
%token DEFINE
%token L_CURLY_BRACKET
%token R_CURLY_BRACKET
%token L_PAREN
%token R_PAREN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token COMMA
%token SEMICOLON
%token PLUS
%token MINUS
%token MULTIPLY
%token DIVIDE
%token REMAINDER
%token INT
%token CHAR
%token VOID
%token DO
%token WHILE
%token IF
%token ELSE
%token FOR
%token PRINTF
%token SCANF
%token RETURN
%token EXIT
%token ADD_ASSIGN
%token MINUS_ASSIGN
%token ASSIGN
%token EQUAL
%token NOT_EQUAL
%token LESS_THAN
%token LESS_EQUAL
%token GREATER_THAN
%token GREATER_EQUAL
%token BITWISE_AND
%token BITWISE_OR
%token BITWISE_XOR
%token BITWISE_NOT
%token LOGICAL_AND
%token LOGICAL_OR
%token NOT
%token TERNARY_CONDITIONAL
%token COLON
%token R_SHIFT
%token L_SHIFT
%token <token> INC
%token <token> DEC
%token <token> NUM_INT
%token <token> NUM_HEXA
%token <token> NUM_OCTAL
%token <token> STRING
%token <token> CHARACTER
%token <token> ID

%type <prog> Programa
%type <func> DeclaracaoOUFuncao
%type <func> ListaFuncoes
%type <token> Declaracoes
%type <func> Funcao
%type <token> DeclaraVariaveisFuncao
%type <ptr> Ponteiro
%type <token> DeclaraVariaveis
%type <token> BlocoVariaveis
%type <dim> ExpressaoColchete
%type <expr> ExpressaoAssign
%type <token> RetornoVariavel
%type <param> DeclaraPrototipos
%type <param> Parametros
%type <param> BlocoParametros
%type <param> RetornaParametros
%type <token> Tipo
%type <cmd> Bloco
%type <cmd> Comandos
%type <cmd> RetornoComandos
%type <cmd> ListaComandos
%type <cmd> AuxElse
%type <expr> AuxFor
%type <expr> AuxPrint
%type <expr> Expressao
%type <token> OpAtrib
%type <token> OpRel
%type <token> OpMult
%type <token> OpUnario
%type <expr> ExpressaoAtribuicao
%type <expr> ExpressaoCondicional
%type <expr> AuxCondicional
%type <expr> ExpressaoOrLogico
%type <expr> ExpressaoAndLogico
%type <expr> ExpressaoOr
%type <expr> ExpressaoXor
%type <expr> ExpressaoAnd
%type <expr> ExpressaoIgual
%type <expr> ExpressaoRelacional
%type <expr> ExpressaoShift
%type <expr> ExpressaoAditiva
%type <expr> ExpressaoMultiplicativa
%type <expr> ExpressaoCast
%type <expr> ExpressaoUnaria
%type <expr> ExpressaoPosFixa
%type <expr> AuxPosFixa
%type <expr> PulaExpressaoAtribuicao
%type <expr> AuxPula
%type <expr> ExpressaoPrimaria
%type <expr> Numero

%start Start

%%

Start: Programa MyEOF { 
        AST = $1;
        erroAux = 0; 
        return 0; 
    }
    | Programa ERRO { erroAux = 1; return 0; }
    | error { erroAux = 1; return 0; } ;

Programa: { 
        void **hash = createHash();
        globalHash = hash;
    } 
    DeclaracaoOUFuncao ListaFuncoes {
        Program *aux = createProgram(globalHash, $2, NULL); // $2 should be a list of functions, therefore Function *
        $$ = aux; 
    } ;

DeclaracaoOUFuncao: Declaracoes { /* inserir na hash global o que quer que apareça aqui */
        // currentHash = globalHash;
        $$ = NULL;
    }
    | Funcao { 
        $$ = $1;  // should return a list of functions
    } ;
    
ListaFuncoes: DeclaracaoOUFuncao ListaFuncoes { 
        if (((Function *) $1) != NULL) {  // se for uma funcao e nao uma declaracao
            $1->next = $2;  // devia linkar as funcoes, sera se ta certo?
            $$ = $1;  // devia retornar aa lista de funcoes
        }
    }
    | { $$ = NULL; } ;

Declaracoes: NUMBER_SIGN DEFINE ID Expressao { /* Adicionar isso na hash */
        if (lookForValueInHash(globalHash, $3.valor, $3.line, $3.column, DEFINE, &textBefore, &semanticError) != -1) {
            void *node = insertHash(globalHash, $3.valor, $3.line, $3.column, DEFINE, 0);
            // evalExpression(node, $4);
            setAssign(node, $4);
        }
    }
    | DeclaraVariaveis { /* Adicionar isso na hash */ }
    | DeclaraPrototipos { /* Adicionar isso na hash */ } ;

Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET {
        // vendo se a funcao ja foi declarada

        if (!lookForPrototypeInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $4, paramsQntd, &textBefore, &semanticError)) {
            if (!lookForValueInHash(globalHash, $3.valor, $3.line, $3.column, $1.type, &textBefore, &semanticError)) {
                void *node = insertHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $2);
                setQntdParams(node, paramsQntd);
                setParam(node, $4);
            } 
        }
        Function *func = createFunction(currentHash, $1.type, $2, $3.valor, $7, NULL);
        paramsQntd = 0;
        currentHash = NULL;
        $$ = func;
    } ;

DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao { /* descendo para colocar na hash da funcao */ }
    | { } ;

Ponteiro: MULTIPLY Ponteiro {
        int ptr = $2 + 1;
        $$ = ptr;
    }
    | { $$ = 0; } ; 

DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON { 
        CURRENT_TYPE = $1.type;
    } ;

BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }

        if (CURRENT_TYPE == 277 && $1 == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: variable '%s' declared void", $2.line, $2.column, $2.valor);
            printLineError($2.line, $2.column);
            if (currentHash) freeHash(currentHash);
            traverseAST(AST);
            exit(1);
        }
        // considerar o ponteiro, dimensoes e atribuicao se existirem
        if (!lookForValueInHash(currentHash, $2.valor, $2.line, $2.column, CURRENT_TYPE, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, $2.valor, $2.line, $2.column, CURRENT_TYPE, $1);
            setDimensions(node, $3);
            // evalExpression(node, $4);
            setAssign(node, $4);
        }
    } ;

ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete {
        // nova struct para dimensoes?
        Dimension *aux = createDimension($2);
        aux->next = $4;
        $$ = aux;
    }
    | { $$ = NULL; } ;

ExpressaoAssign: ASSIGN ExpressaoAtribuicao { 
        $2->assign = ASSIGN;
        $$ = $2;
    }
    | { $$ = NULL; } ;

RetornoVariavel: COMMA BlocoVariaveis { /* colocar na hash */ }
    | { } ; 

DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON { 
        // colocar na hash global e ver se bate com as funcoes ?
        void *node = insertHash(globalHash, $3.valor, $3.line, $3.column, $1.type, $2);
        setPrototype(node);
        setQntdParams(node, paramsQntd);
        setParam(node, $4);
        prototypeParam = NULL;
        paramsQntd = 0;
        free(currentHash);
        currentHash = NULL;
    } ; 

Parametros: L_PAREN BlocoParametros R_PAREN { 
        $$ = prototypeParam;
    } ;

BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros {
        if (!currentHash) {  // hash da funcao
            void **hash = createHash();
            currentHash = hash;
        }

        if ($1.type == 277 && $2 == 0) { // variables of type void not allowed
            if (textBefore) printf("\n");
            printf("error:semantic:%d:%d: variable '%s' declared void", $3.line, $3.column, $3.valor);
            printLineError($3.line, $3.column);
            if (currentHash) freeHash(currentHash);
            traverseAST(AST);
            exit(1);
        }
        paramsQntd++;
        Param *aux = createParam($1.type, $3.valor, $2, $3.line, $3.column+1, $5);
        if (!prototypeParam) prototypeParam = aux;

        if (!lookForValueInHash(currentHash, $3.valor, $3.line, $3.column, $1.type, &textBefore, &semanticError)) {
            void *node = insertHash(currentHash, $3.valor, $3.line, $3.column, $1.type, $2);
            setQntdParams(node, paramsQntd);
            setDimensions(node, $4);
        }

        $$ = aux;
    }
    | { $$ = NULL; } ;

RetornaParametros: COMMA BlocoParametros { 
        $$ = $2;
    }
    | { $$ = NULL; } ;

Tipo: INT {
        if (AUX_CURRENT_TYPE == -1) {
            AUX_CURRENT_TYPE = CURRENT_TYPE;
        }
        CURRENT_TYPE = INT; 
        $$ = yylval.token; 
    }
    | CHAR { 
        if (AUX_CURRENT_TYPE == -1) {
            AUX_CURRENT_TYPE = CURRENT_TYPE;
        }
        CURRENT_TYPE = CHAR;
        $$ = yylval.token;
    }
    | VOID {
        if (AUX_CURRENT_TYPE == -1) {
            AUX_CURRENT_TYPE = CURRENT_TYPE;
        }
        CURRENT_TYPE = VOID;
        $$ = yylval.token;
    } ;

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET { $$ = $2; } ;

Comandos: ListaComandos RetornoComandos {
        $1->next = $2;
        $$ = $1;
    } ;

RetornoComandos: ListaComandos RetornoComandos { 
        $1->next = $2;
        $$ = $1;
    }
    | { $$ = NULL; } ;

ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON {
        Command *aux = createDoWhileStatement($5, $2, NULL);
        $$ = aux;
    }
    | WHILE L_PAREN Expressao R_PAREN Bloco {
        Command *aux = createWhileStatement($3, $5, NULL);
        $$ = aux;
    }
    | IF L_PAREN Expressao R_PAREN Bloco AuxElse {
        Command *aux = createIfStatement($3, $5, $6, NULL);
        $$ = aux;
    }
    | FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco {
        Command *aux = createForStatement($3, $5, $7, $9, NULL);
        $$ = aux;
    }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON {
        Command *aux = createPrintStatement($3.valor, $4, NULL);
        $$ = aux;
    }
    | SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON {
        Command *aux = createScanStatement($6.valor, $3.valor, NULL);
        $$ = aux;
    }
    | EXIT L_PAREN Expressao R_PAREN SEMICOLON {
        Command *aux = createExitStatement($3, NULL);
        $$ = aux; 
    }
    | RETURN AuxFor SEMICOLON {
        Command *aux = createReturnStatement($2, NULL);
        $$ = aux;
    }
    | Expressao SEMICOLON {
        Command *aux = createCommandExpression($1, NULL);
        $$ = aux;
    }
    | SEMICOLON { }
    | Bloco { $$ = $1; } ;

AuxElse: ELSE Bloco {
        $$ = $2;
    }
    | { $$ = NULL; } ;

AuxFor: Expressao { $$ = $1; }
    | { $$ = NULL; } ;

AuxPrint: COMMA Expressao { $$ = $2; }
    | { $$ = NULL; } ;

Expressao: ExpressaoAtribuicao {
        $$ = $1;
    }
    | Expressao COMMA ExpressaoAtribuicao { 
        Expression *aux = createExpression(LISTA_EXP, COMMA, NULL, $1, $3);
        $$ = aux;
    } ;

OpAtrib: ASSIGN { $$ = yylval.token; }
    | ADD_ASSIGN { $$ = yylval.token; }
    | MINUS_ASSIGN { $$ = yylval.token; } ;

OpRel: LESS_THAN { $$ = yylval.token; }
    | LESS_EQUAL { $$ = yylval.token; }
    | GREATER_THAN { $$ = yylval.token; }
    | GREATER_EQUAL { $$ = yylval.token; } ;

OpMult: MULTIPLY { $$ = yylval.token; }
    | DIVIDE { $$ = yylval.token; }
    | REMAINDER { $$ = yylval.token; } ;

OpUnario: BITWISE_AND { $$ = yylval.token; }
    | MULTIPLY { $$ = yylval.token; }
    | PLUS { $$ = yylval.token; }
    | MINUS { $$ = yylval.token; }
    | NOT { $$ = yylval.token; }
    | BITWISE_NOT { $$ = yylval.token; } ;

ExpressaoAtribuicao: ExpressaoCondicional { $$ = $1; }
    | ExpressaoUnaria OpAtrib ExpressaoAtribuicao {
        Expression *aux = createExpression(ATRIBUICAO, $2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoCondicional: ExpressaoOrLogico AuxCondicional {
        $1->ternary = $2;
        $$ = $1;
    }

AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional {
        Expression *aux = createExpression(TERNARY, TERNARY_CONDITIONAL, NULL, $2, $4);
        $$ = aux;
    }
    | { $$ = NULL; } ;

ExpressaoOrLogico: ExpressaoAndLogico { $$ = $1; }
    | ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico { 
        Expression *aux = createExpression(OR_LOGICO, LOGICAL_OR, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoAndLogico: ExpressaoOr { $$ = $1; }
    | ExpressaoAndLogico LOGICAL_AND ExpressaoOr {
        Expression *aux = createExpression(AND_LOGICO, LOGICAL_AND, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoOr: ExpressaoXor { $$ = $1;}
    | ExpressaoOr BITWISE_OR ExpressaoXor {
        Expression *aux = createExpression(OR_BIT, BITWISE_OR, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoXor: ExpressaoAnd { $$ = $1; }
    | ExpressaoXor BITWISE_XOR ExpressaoAnd {
        Expression *aux = createExpression(XOR_BIT, BITWISE_XOR, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoAnd: ExpressaoIgual { $$ = $1; }
    | ExpressaoAnd BITWISE_AND ExpressaoIgual {
        Expression *aux = createExpression(AND_BIT, BITWISE_AND, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoIgual: ExpressaoRelacional { $$ = $1; }
    | ExpressaoIgual EQUAL ExpressaoRelacional {
        Expression *aux = createExpression(IGUALDADE, EQUAL, NULL, $1, $3);
        $$ = aux;
    }
    | ExpressaoIgual NOT_EQUAL ExpressaoRelacional { 
        Expression *aux = createExpression(IGUALDADE, NOT_EQUAL, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoRelacional: ExpressaoShift { $$ = $1; }
    | ExpressaoRelacional OpRel ExpressaoShift { 
        Expression *aux = createExpression(RELACIONAL, $2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoShift: ExpressaoAditiva { $$ = $1; }
    | ExpressaoShift R_SHIFT ExpressaoAditiva {
        Expression *aux = createExpression(SHIFT, R_SHIFT, NULL, $1, $3);
        $$ = aux;
    }
    | ExpressaoShift L_SHIFT ExpressaoAditiva {
        Expression *aux = createExpression(SHIFT, L_SHIFT, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoAditiva: ExpressaoMultiplicativa { $$ = $1; }
    | ExpressaoAditiva PLUS ExpressaoMultiplicativa { 
        Expression *aux = createExpression(ADITIVIVA, PLUS, NULL, $1, $3);
        $$ = aux;
    }   
    | ExpressaoAditiva MINUS ExpressaoMultiplicativa { 
        Expression *aux = createExpression(ADITIVIVA, MINUS, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoMultiplicativa: ExpressaoCast { $$ = $1; }
    | ExpressaoMultiplicativa OpMult ExpressaoCast {
        Expression *aux = createExpression(MULTIPLICATIVA, $2.type, NULL, $1, $3);
        $$ = aux;
    } ;

ExpressaoCast: ExpressaoUnaria { $$ = $1; }
    | L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast {
        // tem qua tratar o ponteiro e fazer alguma coisa com essa expressao
        Expression *aux = createExpression(CASTING, $2.type, NULL, NULL, $5);
        CURRENT_TYPE = AUX_CURRENT_TYPE;
        AUX_CURRENT_TYPE = -1;
        aux->pointer = $3;
    } ;

ExpressaoUnaria: ExpressaoPosFixa { $$ = $1; }
    | INC ExpressaoUnaria {
        Expression *aux = createExpression(UNARIA, INC, NULL, $2, NULL);
        $2->preIncrement = INC; 
        $$ = aux;
    }
    | DEC ExpressaoUnaria {
        Expression *aux = createExpression(UNARIA, DEC, NULL, $2, NULL);
        $2->preIncrement = DEC; 
        $$ = aux;
    }
    | OpUnario ExpressaoCast {
        // Expression *aux = createExpression(UNARIA, $1.type, NULL, $2, NULL);
        $2->unario = $1.type; 
        $$ = $2;
    } ;

ExpressaoPosFixa: ExpressaoPrimaria { $$ = $1; }
    | ExpressaoPosFixa AuxPosFixa {
        $1->right = $2;
        $1->posIncrement = auxPosIncrement;
        auxPosIncrement = 0;
        $$ = $1; 
    } ;

AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET { $$ = $2; }
    | L_PAREN PulaExpressaoAtribuicao R_PAREN { $$ = $2; }
    | INC { auxPosIncrement = INC; }
    | DEC { auxPosIncrement = DEC; } ;

PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula { 
        $1->right = $2; 
        $$ = $1;
    }
    | { $$ = NULL; } ;

AuxPula: COMMA ExpressaoAtribuicao AuxPula {
        $2->right = $3;
        $$ = $2;
    }
    | { $$ = NULL; } ;

ExpressaoPrimaria: ID { 
        Expression *aux = createExpression(PRIMARIA, ID, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | Numero { $$ = $1; }
    | CHARACTER { 
        Expression *aux = createExpression(PRIMARIA, CHARACTER, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | STRING { 
        Expression *aux = createExpression(PRIMARIA, STRING, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | L_PAREN Expressao R_PAREN {
        $$ = $2;
    } ;

Numero: NUM_INT {
        Expression *aux = createExpression(NUMEROS, NUM_INT, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | NUM_HEXA { 
        Expression *aux = createExpression(NUMEROS, NUM_HEXA, $1.valor, NULL, NULL);
        $$ = aux;
    }
    | NUM_OCTAL {
        Expression *aux = createExpression(NUMEROS, NUM_OCTAL, $1.valor, NULL, NULL);
        $$ = aux;
    } ;

%%

void yyerror(void *s) {}

void printLineError(int line, int column) {
    getLineBuffer(line);
        
    printf("\n%s\n", lineBuffer);
    for (int i = 0; i < column - 1; i++) printf(" ");
    printf("^");
}

int main(int argc, char *argv[]) {
    yyparse();

    if (textBefore) printf("\n");
    if (erroAux) {
        int localColumn = yylval.token.column;
        if (yychar == 0 || yychar == MyEOF) {
            printf("error:syntax:%d:%d: expected declaration or statement at end of input", yylval.token.line, yylval.token.column);
        
        } else {
            if (strlen(wrongToken) > 0) {
                localColumn = wrongTokenColumn;
                printf("error:syntax:%d:%d: %s", wrongTokenLine, wrongTokenColumn, wrongToken);
            } else {
                printf("error:syntax:%d:%d: %s", yylval.token.line, yylval.token.column, yylval.token.valor);
            }
        }
        printLineError(yylval.token.line, localColumn);
    
    } else {
        traverseAST(AST);  // se tiver erro semantico vai dar exit e free la dentro
        printf("SUCCESSFUL COMPILATION."); // se chegar aqui, compilou com sucesso e nao tem erros semanticos
    }
    freeAST(AST);   
    return 0;
}