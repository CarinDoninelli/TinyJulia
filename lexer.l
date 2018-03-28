%option noyywrap
%option yylineno
%option nodefault

%{
#include <cstdlib>
#include <cstring>
#include <vector>
#include "tokens.h"

#include "utils.h"

using namespace std;

%}

DIGIT [0-9]
LETTER [a-zA-Z]

%%
"#"[^\n]*                       { /* NOTHING */ }
"#="(.|\n)+"=#"                 { /* NOTHING */ }
[ \t]                           { /* NOTHING */ }
\n                              { return TK_EOL; }
"="                             { return '='; }
"+"                             { return '+'; }
"-"                             { return '-'; }
"*"                             { return '*'; }
"^"                             { return '^'; }
"/"                             { return '/'; }
"%"                             { return '%'; }
"!"                             { return '!'; }
"$"                             { return '$'; }
","                             { return ','; }
"~"                             { return '~'; }
"<<"                            { return TK_LSHIFT; }
">>"                            { return TK_RSHIFT; }
"+="                            { return OP_PLUS_ASSIGN; }
"-="                            { return OP_SUB_ASSIGN; }
"*="                            { return OP_MUL_ASSIGN; }
"/="                            { return OP_DIV_ASSIGN; }
"^="                            { return OP_POW_ASSIGN; }
"%="                            { return OP_MOD_ASSIGN; }
"<"                             { return '<'; }
">"                             { return '>'; }
"<="                            { return OP_LTE; }
">="                            { return OP_GTE; }
"!="                            { return OP_NE; }
"=="                            { return OP_EQ; }
";"                             { return ';'; }
"("                             { return TK_LPAREN; }
")"                             { return TK_RPAREN; }
"{"                             { return TK_LBRACE; }
"}"                             { return TK_RBRACE; }
"["                             { return TK_LBRACK; }
"]"                             { return TK_RBRACK; }
"::"                            { return TK_DOUBLE_COLON; }
":"                             { return ':'; }
"&&"                            { return TK_AND; }
"||"                            { return TK_OR; }
"&"                             { return '&'; }
"|"                             { return '|'; }
"?"                             { return '?'; }
"if"                            { return KW_IF; }
"else"                          { return KW_ELSE; }
"elseif"                        { return KW_ELIF; }
"while"                         { return KW_WHILE; }
"for"                           { return KW_FOR; }
"end"                           { return KW_END; }
"function"                      { return KW_FUNCTION; }
"true"                          { yylval.bool_t = true; return BOOL_LITERAL; }
"false"                         { yylval.bool_t = false; return BOOL_LITERAL; }
"println"                       { return KW_PRINTLN; }
"print"                         { return KW_PRINT; }
"return"                        { return KW_RETURN; }
"Int"                           { return KW_INT; }
"Bool"                          { return KW_BOOL; }
"Array{Int}"                    { return KW_ARRAY; }
"Array{Bool}"                    { return KW_ARRAY; }
"\""[^"]*"\""                   {
                                    yytext[yyleng-1] = '\0';
                                    auto unescaped = strdup(&yytext[1]);
                                    auto escaped = escapedString(unescaped);
                                    yylval.id_t = new string(escaped);
                                    return STRING_LITERAL;
                                }
"'"[^']"'"                      {
                                    yytext[yyleng-1] = '\0';
                                    auto unescaped = strdup(&yytext[1]);
                                    auto escaped = escapedString(unescaped);
                                    yylval.id_t = new string(escaped);
                                    return CHAR_LITERAL;
                                }
{DIGIT}+                        { yylval.num_t = atoi(yytext); return TK_NUM; }
{LETTER}({DIGIT}|{LETTER}|_)*   { yylval.id_t = new string(yytext); return TK_ID; }
.                               { printf("Line %d: Invalid symbol '%c'\n", yylineno, yytext[0]); exit(-1); }
<<EOF>>                         { return 0; }
%%