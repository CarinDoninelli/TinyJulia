//
// Created by Edwin Herrera on 3/20/18.
//

#include "ReturningContext.h"
#include "errors.h"
#include "utils.h"
#include <sstream>

vector<FunctionMeta> FunctionCode::codeBlocks;

void FunctionCode::add(FunctionMeta meta) {
    for (const auto &block : codeBlocks) {
        if (block.name == meta.name && block.paramTypes == meta.paramTypes) {
            throw FunctionRedeclarationError(meta.name);
        }
    }

    codeBlocks.push_back(move(meta));
}

string FunctionCode::joined() {
    stringstream ss;
    for (const auto &block : codeBlocks) {
        ss << block.code << endl;
    }
    return ss.str();
}

FunctionMeta FunctionCode::find(const string &name, const vector<ReturnType> &argumentTypes) {
    for (const auto &block : codeBlocks) {
        if (block.name == name && block.paramTypes == argumentTypes) {
            return block;
        }
    }

    throw UndefinedFunctionError(name);
}

map<string, string> *LiteralCode::literals = new map<string, string> { // NOLINT
        pair<string, string> { "\"%d\", 10, 0", "print_fmt_int" }
};


void LiteralCode::add(string literal, string label) {
    if (literals->find(literal) == literals->end()) {
        literals->insert(pair<string, string>{ literal, move(label) });
    }
}

string LiteralCode::findLabel(const string &literal) {
    if (literals->find(literal) != literals->end()) {
        return literals->at(literal);
    }

    auto label = newLabel();
    add(literal, label);
    return label;
}

string LiteralCode::joined() {
    stringstream ss;
    for (const auto &literal : *literals) {
        ss << literal.second << ": db " << literal.first << endl;
    }
    return ss.str();
}
