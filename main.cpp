#include "include/lexer.h"
#include "include/parser.h"
#include "include/codegen.h"
#include <iostream>

int main() {
    std::string input = "kudasai akari(p: string) yamete {}";
    Lexer lexer(input);
    Parser parser(lexer);
    AstNode rootNode = parser.parseFunction();
    CodeGenerator codegen;
    codegen.generate(rootNode);
    return 0;
}

