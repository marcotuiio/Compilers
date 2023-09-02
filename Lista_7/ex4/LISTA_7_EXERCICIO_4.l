%option yylineno
%{
int blankLines = 0;
int linesComment = 0;
int noBlankNoCommentLines = 0;
int semiColons = 0;
int prepocDirectives = 0; 
int totalDirectives = 0;
int is_blank_line = 0;
%}

%%

";" { semiColons++; }
"//". { linesComment++; }
"\n" {
    if (is_blank_line) {
        blankLines++;
    }
    is_blank_line = 1;
}
. { is_blank_line = 0; }
[ \t]+ {}
"#"("include"|"define") { prepocDirectives++; }

%%

int yywrap() {}

int main(int argc, char *argv[]) {

    if(argc < 2) { /* just read stdin */
        yylex();
        return 0;
    }

    for (int i = 1; i < argc; i++) {
        FILE *f = fopen(argv[i], "r");
        if(!f) {
            printf("Unable to open file %s\n", argv[i]);
            return 1;
        }

        yyrestart(f);
        yylex();
        fclose(f);
        noBlankNoCommentLines = yylineno - blankLines - linesComment;
        printf("\n\n (%s) totalLines %d blankLines %d linesComment %d noBlankNoCommentLines %d semiColons %d prepocDirectives %d\n", argv[i], yylineno, blankLines, linesComment, noBlankNoCommentLines, semiColons, prepocDirectives);
        yylineno = 1;
        blankLines = 0;
        linesComment = 0;
        noBlankNoCommentLines = 0;
        semiColons = 0;
        prepocDirectives = 0; 
        totalDirectives += prepocDirectives;
    }
    return 0;
}