/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    MyEOF = 258,                   /* MyEOF  */
    ERRO = 259,                    /* ERRO  */
    NUMBER_SIGN = 260,             /* NUMBER_SIGN  */
    DEFINE = 261,                  /* DEFINE  */
    L_CURLY_BRACKET = 262,         /* L_CURLY_BRACKET  */
    R_CURLY_BRACKET = 263,         /* R_CURLY_BRACKET  */
    L_PAREN = 264,                 /* L_PAREN  */
    R_PAREN = 265,                 /* R_PAREN  */
    L_SQUARE_BRACKET = 266,        /* L_SQUARE_BRACKET  */
    R_SQUARE_BRACKET = 267,        /* R_SQUARE_BRACKET  */
    COMMA = 268,                   /* COMMA  */
    SEMICOLON = 269,               /* SEMICOLON  */
    PLUS = 270,                    /* PLUS  */
    MINUS = 271,                   /* MINUS  */
    MULTIPLY = 272,                /* MULTIPLY  */
    DIVIDE = 273,                  /* DIVIDE  */
    REMAINDER = 274,               /* REMAINDER  */
    INT = 275,                     /* INT  */
    CHAR = 276,                    /* CHAR  */
    VOID = 277,                    /* VOID  */
    DO = 278,                      /* DO  */
    WHILE = 279,                   /* WHILE  */
    IF = 280,                      /* IF  */
    ELSE = 281,                    /* ELSE  */
    FOR = 282,                     /* FOR  */
    PRINTF = 283,                  /* PRINTF  */
    SCANF = 284,                   /* SCANF  */
    RETURN = 285,                  /* RETURN  */
    EXIT = 286,                    /* EXIT  */
    ADD_ASSIGN = 287,              /* ADD_ASSIGN  */
    MINUS_ASSIGN = 288,            /* MINUS_ASSIGN  */
    ASSIGN = 289,                  /* ASSIGN  */
    EQUAL = 290,                   /* EQUAL  */
    NOT_EQUAL = 291,               /* NOT_EQUAL  */
    LESS_THAN = 292,               /* LESS_THAN  */
    LESS_EQUAL = 293,              /* LESS_EQUAL  */
    GREATER_THAN = 294,            /* GREATER_THAN  */
    GREATER_EQUAL = 295,           /* GREATER_EQUAL  */
    BITWISE_AND = 296,             /* BITWISE_AND  */
    BITWISE_OR = 297,              /* BITWISE_OR  */
    BITWISE_XOR = 298,             /* BITWISE_XOR  */
    BITWISE_NOT = 299,             /* BITWISE_NOT  */
    LOGICAL_AND = 300,             /* LOGICAL_AND  */
    LOGICAL_OR = 301,              /* LOGICAL_OR  */
    NOT = 302,                     /* NOT  */
    TERNARY_CONDITIONAL = 303,     /* TERNARY_CONDITIONAL  */
    COLON = 304,                   /* COLON  */
    R_SHIFT = 305,                 /* R_SHIFT  */
    L_SHIFT = 306,                 /* L_SHIFT  */
    INC = 307,                     /* INC  */
    DEC = 308,                     /* DEC  */
    NUM_INT = 309,                 /* NUM_INT  */
    NUM_HEXA = 310,                /* NUM_HEXA  */
    NUM_OCTAL = 311,               /* NUM_OCTAL  */
    STRING = 312,                  /* STRING  */
    CHARACTER = 313,               /* CHARACTER  */
    ID = 314                       /* ID  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 45 "sintatico.y"

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

#line 139 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
