%option yylineno
%{
int blankLines = 0;
int linesComment = 0;
int noBlankNoCommentLines = 0;
int semiColons = 0;
int prepocDirectives = 0;
int totalLines = 0;
int totalBlankLines = 0;
int totalLinesComment = 0;
int totalNoBlankNoCommentLines = 0;
int totalSemiColons = 0; 
int totalDirectives = 0;
int isBlankLine = 0;
%}

%%

";" { semiColons++; }
"//". { linesComment++; }
"\n" {
    if (isBlankLine) {
        blankLines++;
    }
    isBlankLine = 1;
}
. { isBlankLine = 0; }
"#"("include"|"define") { prepocDirectives++; }

%%

int yywrap() {}

int main(int argc, char *argv[]) {

    if(argc < 2) { /* just read stdin */
        yylex();
        return 0;
    }

    printf("total  blank  lines w/  nb, nc  semi-  preproc.  file\n");
    printf("lines  lines  comments  lines  colons  direct.  \n");
    printf("------+-------+-------+-------+-------+-------+-------");

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
        printf("\n%4d\t%4d\t%4d\t%4d\t%4d\t%4d\t%s", yylineno, blankLines, linesComment, noBlankNoCommentLines, semiColons, prepocDirectives, argv[i]);
       
        totalLines += yylineno;
        totalBlankLines += blankLines;
        totalLinesComment += linesComment;
        totalNoBlankNoCommentLines += noBlankNoCommentLines;
        totalSemiColons += semiColons;
        totalDirectives += prepocDirectives;

        yylineno = 1;
        blankLines = 0;
        linesComment = 0;
        noBlankNoCommentLines = 0;
        semiColons = 0;
        prepocDirectives = 0; 
    }
    printf("\n%4d\t%4d\t%4d\t%4d\t%4d\t%4d\ttotal", totalLines, totalBlankLines, totalLinesComment, totalNoBlankNoCommentLines, totalSemiColons, totalDirectives);
    return 0;
}