cmake_minimum_required(VERSION 3.7)
project(TinyJuliaPP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TinyJuliaPP main.cpp ast.cpp ast.h scope.cpp scope.h types.h ReturningContext.h checks.cpp checks.h utils.cpp utils.h errors.h ReturningContext.cpp errors parser.cpp lexer.cpp)