#include <iostream>
#include <vector>
#include "ast.h"

using namespace std;


extern FILE *yyin;
extern int yylineno;
extern int errors;
extern Expression *expression;

int yylex();
int yyparse();

int main(int argc, char *argv[]) {

    if (argc != 2) {
		fprintf(stderr, "Usage: %s <input file>\n", argv[0]);
		return 1;
	}

	yyin = fopen(argv[1], "rb");
	if (yyin == NULL) {
		fprintf(stderr, "Cannot open input file '%s'\n", argv[1]);
		return 2;
	}
	errors = 0;
	yylineno = 1;
	yyparse();

    auto result = expression->evaluate(new Scope());

    cout << "global main" << endl
         << FunctionCode::externFunctionCode() << endl
         << "section .data" << endl
         << LiteralCode::joined() << endl
         << "section .text" << endl
         << "main:" << endl
         << "push ebp" << endl
         << "mov ebp, esp" << endl
         << result.code
         << "leave" << endl
         << "ret" << endl
         << FunctionCode::joined();

    return 0;
}