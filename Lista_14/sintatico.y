%{

#include <stdio.h>
#include <string.h>

extern int yylex();

extern int textBefore;
extern int yychar;
extern int myEof;
extern int erroLexico;
extern int linhaDescartavel;
int erroAux = 0;
int erroSintatico = 0;
int charAtError;
void yyerror(void *s);

%}

%union {
    struct {
        char *valor;
        int column;
        int line;
        int type;
    } token;
}

%token EOL
%token ADD
%token SUB
%token MUL
%token DIV
%token POW
%token MOD
%token L_PAREN
%token R_PAREN
%token SEN
%token COS
%token TAN
%token ABS
%token ID
%token REAL
%token INT
%token ERRO

%start Start

%left '+' '-'
%left '*' '/'
%right '^'

%%

/* 
Start -> Exp EOL
Exp -> Fator
Exp -> Exp ADD Fator
Exp -> Exp SUB Fator
Fator -> Termo
Fator -> Fator MUL Termo
Fator -> Fator DIV Termo
Fator -> Fator POW Termo
Fator -> Fator MOD Termo
Termo -> L_PAREN Exp R_PAREN
Termo -> SEN L_PAREN Exp R_PAREN
Termo -> COS L_PAREN Exp R_PAREN
Termo -> TAN L_PAREN Exp R_PAREN
Termo -> ABS L_PAREN Exp R_PAREN
Termo -> ID
Termo -> INT
Termo -> REAL

*/

Start: Exp EOL { erroSintatico = 0; return 0; }
    | Exp ERRO { erroAux = 1; return 0; }
    | error { erroSintatico = 1; charAtError = yychar; return 0;  }
;

Exp: Fator { }
    | Exp ADD Fator { } 
    | Exp SUB Fator { }
;

Fator: Termo { }
    | Fator MUL Termo { }
    | Fator DIV Termo { }
    | Fator POW Termo { }
    | Fator MOD Termo { } ;

Termo: L_PAREN Exp R_PAREN { } 
    | ID { }
    | INT { }
    | REAL { }
    | ADD Termo { }
    | SUB Termo { }
    | SEN L_PAREN Exp R_PAREN { }
    | COS L_PAREN Exp R_PAREN { }
    | TAN L_PAREN Exp R_PAREN { }
    | ABS L_PAREN Exp R_PAREN { } ;

%%

void yyerror(void *s) {}

void resetAux() {
    erroAux = 0; 
    erroLexico = 0;
    erroSintatico = 0;
    linhaDescartavel = 0;
}

void goToNextLine() {
    while (yylex() != EOL);
}

int main(int argc, char* argv[]) {
    while (!myEof) {
        yyparse();

        if (erroLexico && !erroAux) continue;  // tem erro lexico mais ainda nao acabou a linha
        if (erroAux) { // tem erro lexico e acabou a linha
            resetAux();
            continue;
        }

        if (textBefore) printf("\n");

        // if (!linhaDescartavel) {
        //     resetAux();
        //     continue;
        // }

        if (erroSintatico) { // tem erro sintatico

            if (charAtError == 0 || charAtError == EOL || charAtError == YYEMPTY) {  // acabou a linha subitamente
                printf("A expressao terminou de forma inesperada. %d ", charAtError);
            } else {  // tem erro sintatico no meio da linha
                printf("Erro sinatico na coluna [%d][%d]: %s", yylval.token.line, yylval.token.column, yylval.token.valor);
            }
            
            // yyclearin;
            // goToNextLine();
            // resetAux();

        } else {
            printf("EXPRESSAO CORRETA");
            resetAux();     
        }
        textBefore = 1; 
    } 

    return 0;
}
