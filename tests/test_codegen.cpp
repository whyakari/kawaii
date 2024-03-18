#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/codegen.h"
#include <iostream>

int main() {
    Lexer lexer("fn add(a: int, b: int) -> int { return a + b; }");
    Parser parser(lexer);
    CodeGenerator codegen(parser);

    std::cout << "Source code: fn add(a: int, b: int) -> int { return a + b; }\n";

    try {
        codegen.generate();
    } catch (const std::exception& e) {
        std::cerr << "Code generation error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}

