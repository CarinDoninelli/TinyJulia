/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

#ifndef YY_YY_TOKENS_H_INCLUDED
# define YY_YY_TOKENS_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y" /* yacc.c:1915  */

    #include <string>
    #include "ast.h"

#line 49 "tokens.h" /* yacc.c:1915  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_NUM = 258,
    TK_ID = 259,
    STRING_LITERAL = 260,
    CHAR_LITERAL = 261,
    BOOL_LITERAL = 262,
    KW_IF = 263,
    KW_ELSE = 264,
    KW_WHILE = 265,
    KW_FOR = 266,
    KW_PRINTLN = 267,
    KW_END = 268,
    KW_ELIF = 269,
    KW_PRINT = 270,
    KW_FUNCTION = 271,
    KW_BOOL = 272,
    KW_INT = 273,
    KW_RETURN = 274,
    TK_EOL = 275,
    TK_LPAREN = 276,
    TK_RPAREN = 277,
    TK_LBRACK = 278,
    TK_RBRACK = 279,
    TK_DOUBLE_COLON = 280,
    TK_LBRACE = 281,
    TK_RBRACE = 282,
    OP_PLUS_ASSIGN = 283,
    OP_SUB_ASSIGN = 284,
    OP_MUL_ASSIGN = 285,
    OP_DIV_ASSIGN = 286,
    OP_MOD_ASSIGN = 287,
    OP_POW_ASSIGN = 288,
    OP_LTE = 289,
    OP_GTE = 290,
    OP_NE = 291,
    OP_EQ = 292,
    TK_AND = 293,
    TK_OR = 294,
    TK_RSHIFT = 295,
    TK_LSHIFT = 296
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 30 "parser.y" /* yacc.c:1915  */

    string *id_t;
    int num_t;
    bool bool_t;
    Expression *expression_t;
    vector<Expression *> *expression_list_t;
    ReturnType type_t;

#line 112 "tokens.h" /* yacc.c:1915  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TOKENS_H_INCLUDED  */
