%code requires {
    #include <string>
    #include "ast.h"
}

%{
    #include <cstdio>
    #include <string>
    #include <iostream>

    #include "ast.h"

    using namespace std;

    extern int yylineno;

    int yylex();

    void yyerror(const char *str)
    {
        printf("Line %d: %s\n", yylineno, str);
    }

    #define YYERROR_VERBOSE 1

    Expression *expression;
%}

%union {
    string *id_t;
    int num_t;
    bool bool_t;
    Expression *expression_t;
    vector<Expression *> expression_list_t;
}

%token<num_t> TK_NUM
%token<id_t> TK_ID
%token<id_t> STRING_LITERAL CHAR_LITERAL
%token<bool_t> BOOL_LITERAL
%token KW_IF KW_ELSE KW_WHILE KW_FOR KW_PRINTLN KW_END KW_ELIF KW_PRINT KW_FUNCTION KW_BOOL KW_INT
%token KW_RETURN
%token TK_EOL
%token TK_LPAREN TK_RPAREN TK_LBRACK TK_RBRACK TK_DOUBLE_COLON TK_LBRACE TK_RBRACE
%token OP_PLUS_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN OP_POW_ASSIGN
%token OP_LTE OP_GTE OP_NE OP_EQ
%token TK_AND TK_OR
%token TK_RSHIFT TK_LSHIFT

%expect 0

%%



%%