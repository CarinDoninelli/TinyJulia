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

    int errors;
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
    vector<FunctionDeclaration::Param> *params_t;
}

%token<num_t> TK_NUM
%token<id_t> TK_ID
%token<id_t> STRING_LITERAL CHAR_LITERAL
%token<bool_t> BOOL_LITERAL
%token KW_IF KW_ELSE KW_WHILE KW_FOR KW_PRINTLN KW_END KW_ELIF KW_PRINT KW_FUNCTION KW_BOOL KW_INT KW_ARRAY
%token KW_RETURN
%token TK_EOL
%token TK_LPAREN TK_RPAREN TK_LBRACK TK_RBRACK TK_DOUBLE_COLON TK_LBRACE TK_RBRACE
%token OP_PLUS_ASSIGN OP_SUB_ASSIGN OP_MUL_ASSIGN OP_DIV_ASSIGN OP_MOD_ASSIGN OP_POW_ASSIGN
%token OP_LTE OP_GTE OP_NE OP_EQ
%token TK_AND TK_OR
%token TK_RSHIFT TK_LSHIFT

%type<type_t> type optType
%type<params_t> function_params
%type<expression_list_t> statement_list print_argument_list expression_list
%type<expression_t> unending_block
%type<expression_t> statement print_statement declaration_statement
%type<expression_t> print_argument while if else for function return
%type<expression_t> expression
%type<expression_t> assignment postfix 
%type<expression_t> condition_or condition_and
%type<expression_t> bitwise_or bitwise_xor bitwise_and
%type<expression_t> relational arithmetic term exponent unary factor

%expect 0

%%

program: opEol statement_list opEol  { expression = new Block(*$2); }
;

new_line: new_line TK_EOL
    | TK_EOL
    | ';'
;

opEol: new_line
    | %empty
;

unending_block: TK_EOL opEol statement_list opEol { $$ = new Block(*$3); }
;

statement_list: statement_list new_line statement { $$ = $1; $$->push_back($3); }
        | statement                               { $$ = new vector<Expression *>{ $1 }; }
;

statement: print_statement  { $$ = $1; }
    | declaration_statement { $$ = $1; }
    | assignment            { $$ = $1; }
    | while                 { $$ = $1; }
    | if                    { $$ = $1; }
    | for                   { $$ = $1; }
    | function              { $$ = $1; }
    | return                { $$ = $1; }
;

return: KW_RETURN expression { $$ = new Return($2); }
;

function: KW_FUNCTION TK_ID TK_LPAREN function_params TK_RPAREN optType unending_block KW_END { $$ = new FunctionDeclaration(*$2, *$4, $6, $7); }
;

function_params: function_params ',' TK_ID type { $$ = $1; $$->push_back(FunctionDeclaration::Param{*$3, $4}); }
        | TK_ID type { $$ = new vector<FunctionDeclaration::Param>{ FunctionDeclaration::Param(*$1, $2) }; }
;

for: KW_FOR TK_ID '=' expression ':' expression unending_block KW_END { $$ = new For(*$2, $4, $6, $7); }
;

if: KW_IF expression unending_block else { $$ = new If($2, $3, $4); }
;

else: KW_ELIF expression unending_block else { $$ = new If($2, $3, $4); }
    | KW_ELSE unending_block KW_END          { $$ = $2; }
    | KW_END                                 { $$ = nullptr; }
;

while: KW_WHILE expression unending_block KW_END { $$ = new While($2, $3); }
;

print_statement: KW_PRINTLN TK_LPAREN print_argument_list TK_RPAREN { $$ = new Print{ *$3, true }; }
        | KW_PRINT TK_LPAREN print_argument_list TK_RPAREN          { $$ = new Print{ *$3, false }; }
;

print_argument_list: print_argument_list ',' print_argument { $$ = $1; $$->push_back($3); }
        | print_argument                                    { $$ = new vector<Expression*>; $$->push_back($1); }
;

print_argument: STRING_LITERAL { $$ = new StringExpression{ *$1 }; }
        | expression           { $$ = $1; }
;

declaration_statement: TK_ID type '=' expression { $$ = new Declaration{ *$1, $2, $4 }; }
;

type: TK_DOUBLE_COLON KW_INT   { $$ = ReturnType::INTEGER; }
    | TK_DOUBLE_COLON KW_BOOL  { $$ = ReturnType::BOOL; }
    | TK_DOUBLE_COLON KW_ARRAY { $$ = ReturnType::INT_ARRAY; }
;

optType: type { $$ = $1; }
    | %empty  { $$ = ReturnType::UNIT; }
;

expression: assignment { $$ = $1; }
;

assignment: postfix '=' assignment      { $$ = new Assignment{ $1, $3 }; }
    | postfix OP_PLUS_ASSIGN assignment { $$ = new Assignment{ $1, new AddExpression{ $1, $3 } };  }
    | postfix OP_SUB_ASSIGN assignment  { $$ = new Assignment{ $1, new SubExpression{ $1, $3 } };  }
    | postfix OP_MUL_ASSIGN assignment  { $$ = new Assignment{ $1, new MulExpression{ $1, $3 } };  }
    | postfix OP_DIV_ASSIGN assignment  { $$ = new Assignment{ $1, new DivExpression{ $1, $3 } };  }
    | postfix OP_MOD_ASSIGN assignment  { $$ = new Assignment{ $1, new ModExpression{ $1, $3 } };  }
    | postfix OP_POW_ASSIGN assignment  { $$ = new Assignment{ $1, new PowExpression{ $1, $3 } };  }
    | condition_or                      { $$ = $1; }
;

condition_or: condition_or TK_OR condition_and { $$ = new OrExpression{ $1, $3 }; }
        | condition_and                        { $$ = $1; }
;

condition_and: condition_and TK_AND bitwise_or { $$ = new AndExpression{ $1, $3 }; }
        | bitwise_or                           { $$ = $1; }
;

bitwise_or: bitwise_or '|' bitwise_xor { $$ = new BitwiseOrExpression{ $1, $3 }; }
    | bitwise_xor                      { $$ = $1; }
;

bitwise_xor: bitwise_xor '$' bitwise_and { $$ = new XorExpression{ $1, $3 }; }
    | bitwise_and                        { $$ = $1; }
;

bitwise_and: bitwise_and '&' relational { $$ = new BitwiseAndExpression{ $1, $3 }; }
    | relational                        { $$ = $1; }
;

relational: relational OP_EQ arithmetic { $$ = new EqualExpression{ $1, $3 };              }
    | relational OP_NE arithmetic       { $$ = new NotEqualExpression{ $1, $3 };           }
    | relational '>' arithmetic         { $$ = new GreaterThanExpression{ $1, $3 };        }
    | relational '<' arithmetic         { $$ = new LessThanExpression{ $1, $3 };           }
    | relational OP_GTE arithmetic      { $$ = new GreaterThanOrEqualExpression{ $1, $3 }; }
    | relational OP_LTE arithmetic      { $$ = new LessThanOrEqualExpression{ $1, $3 };    }
    | arithmetic                        { $$ = $1; }
;

arithmetic: arithmetic '-' term { $$ = new SubExpression($1, $3); }
    | arithmetic '+' term       { $$ = new AddExpression($1, $3); }
    | term                      { $$ = $1; }
;

term: term '*' exponent { $$ = new MulExpression($1, $3);  }
    | term '/' exponent { $$ = new DivExpression($1, $3);  }
    | term '%' exponent { $$ = new ModExpression($1, $3);  }
    | exponent { $$ = $1; }
;

exponent: exponent '^' unary { $$ = new PowExpression($1, $3); }
    | unary                  { $$ = $1; }
;

unary: '-' unary { $$ = new UnaryMinus($2); }
    |  '!' unary { $$ = new Negation($2); }
    |  postfix   { $$ = $1; }
;

factor: TK_NUM                               { $$ = new IntExpression($1); }
    |   BOOL_LITERAL                         { $$ = new BoolExpression($1); }
    |   TK_LBRACK expression_list TK_RBRACK  { $$ = new Array(*$2); }
    |   TK_ID                                { $$ = new IdExpression(*$1); }
    |   TK_ID TK_LBRACK expression TK_RBRACK { $$ = new ArrayAccess(*$1, new SubExpression($3, new IntExpression(1))); }
    |   TK_LPAREN expression TK_RPAREN       { $$ = $2; }
;

postfix: factor                                 { $$ = $1; }
    | TK_ID TK_LPAREN expression_list TK_RPAREN { $$ = new FunctionCall{ *$1, *$3 }; }
    | TK_ID TK_LPAREN TK_RPAREN                 { $$ = new FunctionCall{ *$1, vector<Expression *>() }; }
;

expression_list: expression_list ',' expression { $$ = $1; $$->push_back($3); }
        | expression                            { $$ = new vector<Expression *>{ $1 }; }
;

%%