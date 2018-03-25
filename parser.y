%code requires {
    #include <string>
    #include "ast.h"
}

%{
    #include <cstdio>
    #include <string>
    #include <iostream>

    #include "ast.h"
    #include "types.h"

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
    vector<Expression *> *expression_list_t;
    ReturnType type_t;
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

%type<expression_t> program
%type<type_t> type
%type<expression_list_t> statement_list print_argument_list
%type<expression_t> unending_block ending_block
%type<expression_t> statement print_statement, declaration_statement
%type<expression_t> print_argument 
%type<expression_t> expression

%expect 0

%%

program: unending_block  { $$ = $1; }
;

new_line: new_line TK_EOL
    | TK_EOL
;

optEOL: new_line
    | %empty
;

unending_block: statement_list { $$ = new Block(*$1); }
;

ending_block: unending_block KW_END { $$ = $1; }
;

statement_list: statement_list new_line statement { $$ = $1; $$->push_back($3); }
        | statement { $$ = new vector<Expression *>{ $1 }; }
;

statement: print_statement  { $$ = $1; }
    | declaration_statement { $$ = $1; }
;

print_statement: KW_PRINTLN '(' print_argument_list ')' { $$ = new Print{ *$3 }; }
;

print_argument_list: print_argument_list ',' print_argument { $$ = $1; $$->push_back($3); }
        | print_argument { $$ = new vector<Expression*>; $$->push_back($1); }
;

print_argument: STRING_LITERAL { $$ = new StringExpression{ *$1 } }
        | expression { $$ = $1; }
;

declaration_statement: TK_ID type '=' expression { $$ = new Declaration{ *$1, *$2, $4 }; }
;

type: TK_DOUBLE_COLON KW_INT  { $$ = ReturnType::INTEGER; }
    | TK_DOUBLE_COLON KW_BOOL { $$ = ReturnType::BOOL; }
;

expression: {  }
;

%%