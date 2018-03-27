#!/bin/sh

bison --defines=tokens.h -o parser.cpp parser.y
flex -o lexer.cpp lexer.l