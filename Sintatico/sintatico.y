%{

#include <stdio.h>
#include <string.h>

extern int yylex();
void yyerror(void *s);

extern char *yytext;
extern int yychar;
extern int textBefore;
extern char lineBuffer[2048];
extern void getLineBuffer();

extern char wrongToken[32];
extern int wrongTokenLine;
extern int wrongTokenColumn;

int erroAux = 0;

%}

%union {
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
%token INC
%token DEC
%token NUM_INT
%token NUM_HEXA
%token NUM_OCTAL
%token STRING
%token CHARACTER
%token ID

%start Start

%%

Start: Programa MyEOF { erroAux = 0; return 0; }
    | Programa ERRO { erroAux = 1; return 0; }
    | error { erroAux = 1; return 0; }
;

Programa: Declaracoes AuxPrograma { }
    | Funcao AuxPrograma { }
;

AuxPrograma: Programa AuxPrograma { }
    | { }

Declaracoes: NUMBER_SIGN DEFINE ID Expressao { }
    | DeclaraVariaveis { }
    | DeclaraPrototipos { }
;

Funcao: Tipo Ponteiro ID Parametros L_CURLY_BRACKET DeclaraVariaveisFuncao Comandos R_CURLY_BRACKET { }
;

DeclaraVariaveisFuncao: DeclaraVariaveis DeclaraVariaveisFuncao { }
    | { }
;

Ponteiro: MULTIPLY Ponteiro { }
    | { }
;

DeclaraVariaveis: Tipo BlocoVariaveis SEMICOLON { }
;

BlocoVariaveis: Ponteiro ID ExpressaoColchete ExpressaoAssign RetornoVariavel { }
;

ExpressaoColchete: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET ExpressaoColchete { }
    | { }
;

ExpressaoAssign: ASSIGN ExpressaoAtribuicao { }
    | { }

RetornoVariavel: COMMA BlocoVariaveis { }
    | { }
; 

DeclaraPrototipos: Tipo Ponteiro ID Parametros SEMICOLON { }
; 

Parametros: L_PAREN BlocoParametros R_PAREN { }
;

BlocoParametros: Tipo Ponteiro ID ExpressaoColchete RetornaParametros { }
    | { }
;

RetornaParametros: COMMA BlocoParametros { }
    | { }

Tipo: INT { }
    | CHAR { }
    | VOID { }
;

Bloco: L_CURLY_BRACKET Comandos R_CURLY_BRACKET { }
;

Comandos: ListaComandos RetornoComandos { }
;

RetornoComandos: ListaComandos RetornoComandos { }
    | { }
;

ListaComandos: DO Bloco WHILE L_PAREN Expressao R_PAREN SEMICOLON { }
    | WHILE L_PAREN Expressao R_PAREN Bloco { }
    | IF L_PAREN Expressao R_PAREN Bloco AuxElse { }
    | FOR L_PAREN AuxFor SEMICOLON AuxFor SEMICOLON AuxFor R_PAREN Bloco { }
    | PRINTF L_PAREN STRING AuxPrint R_PAREN SEMICOLON { }
    | SCANF L_PAREN STRING COMMA BITWISE_AND ID R_PAREN SEMICOLON { }
    | EXIT L_PAREN Expressao R_PAREN SEMICOLON { }
    | RETURN AuxFor SEMICOLON { }
    | Expressao SEMICOLON { }
    | SEMICOLON { }
    | Bloco { }
;

AuxElse: ELSE Bloco { }
    | { }
;

AuxFor: Expressao { }
    | { }
;

AuxPrint: COMMA Expressao { }
    | { }
;

Expressao: ExpressaoAtribuicao { }
    | Expressao COMMA ExpressaoAtribuicao { }
;

OpAtrib: ASSIGN { }
    | ADD_ASSIGN { }
    | MINUS_ASSIGN { }
;

OpRel: LESS_THAN { }
    | LESS_EQUAL { }
    | GREATER_THAN { }
    | GREATER_EQUAL { }
;

OpMult: MULTIPLY { }
    | DIVIDE { }
    | REMAINDER { }
;

OpUnario: BITWISE_AND { }
    | MULTIPLY { }
    | PLUS { }
    | MINUS { }
    | NOT { }
    | BITWISE_NOT { }
;

ExpressaoAtribuicao: ExpressaoCondicional { }
    | ExpressaoUnaria OpAtrib ExpressaoAtribuicao { }
;

ExpressaoCondicional: ExpressaoOrLogico AuxCondicional { }
;

AuxCondicional: TERNARY_CONDITIONAL Expressao COLON ExpressaoCondicional { }
    | { }

ExpressaoOrLogico: ExpressaoAndLogico { }
    | ExpressaoOrLogico LOGICAL_OR ExpressaoAndLogico { }
;

ExpressaoAndLogico: ExpressaoOr { }
    | ExpressaoAndLogico LOGICAL_AND ExpressaoOr { }
;

ExpressaoOr: ExpressaoXor { }
    | ExpressaoOr BITWISE_OR ExpressaoXor { }
;

ExpressaoXor: ExpressaoAnd { }
    | ExpressaoXor BITWISE_XOR ExpressaoAnd { }
;

ExpressaoAnd: ExpressaoIgual { }
    | ExpressaoAnd BITWISE_AND ExpressaoIgual { }
;

ExpressaoIgual: ExpressaoRelacional { }
    | ExpressaoIgual EQUAL ExpressaoRelacional { }
    | ExpressaoIgual NOT_EQUAL ExpressaoRelacional { }
;

ExpressaoRelacional: ExpressaoShift { }
    | ExpressaoRelacional OpRel ExpressaoShift { }

ExpressaoShift: ExpressaoAditiva { }
    | ExpressaoShift R_SHIFT ExpressaoAditiva { }
    | ExpressaoShift L_SHIFT ExpressaoAditiva { }
;

ExpressaoAditiva: ExpressaoMultiplicativa { }
    | ExpressaoAditiva PLUS ExpressaoMultiplicativa { }
    | ExpressaoAditiva MINUS ExpressaoMultiplicativa { }
;

ExpressaoMultiplicativa: ExpressaoCast { }
    | ExpressaoMultiplicativa OpMult ExpressaoCast { }
;

ExpressaoCast: ExpressaoUnaria { }
    | L_PAREN Tipo Ponteiro R_PAREN ExpressaoCast { }
;

ExpressaoUnaria: ExpressaoPosFixa { }
    | INC ExpressaoUnaria { }
    | DEC ExpressaoUnaria { }
    | OpUnario ExpressaoCast { }
;

ExpressaoPosFixa: ExpressaoPrimaria { }
    | ExpressaoPosFixa AuxPosFixa { }
;

AuxPosFixa: L_SQUARE_BRACKET Expressao R_SQUARE_BRACKET { }
    | L_PAREN PulaExpressaoAtribuicao R_PAREN { }
    | INC { }
    | DEC { }
;

PulaExpressaoAtribuicao: ExpressaoAtribuicao AuxPula { }
    | { }
;

AuxPula: COMMA ExpressaoAtribuicao AuxPula { }
    | { }
;

ExpressaoPrimaria: ID { }
    | Numero { }
    | CHARACTER { }
    | STRING { }
    | L_PAREN Expressao R_PAREN { }
;

Numero: NUM_INT { }
    | NUM_HEXA { }
    | NUM_OCTAL { }
;

%%

void yyerror(void *s) {}

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

        getLineBuffer(yylval.token.line);
        
        printf("\n%s\n", lineBuffer);
        for (int i = 0; i < localColumn - 1; i++) printf(" ");
        printf("^");

    } else {
        printf("SUCCESSFUL COMPILATION.");
    }

    return 0;
}
