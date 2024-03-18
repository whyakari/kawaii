#include "../include/lexer.h"
#include "../include/parser.h"
#include <iostream>

void testParser(const std::string& source) {
    Lexer lexer(source);
    Parser parser(lexer);

    std::cout << "Source code: " << source << "\n";

    try {
        parser.parse();
        std::cout << "Parse successful\n\n";
    } catch (const std::exception& e) {
        std::cerr << "Parse error: " << e.what() << "\n";
    }
}

int main() {
    testParser("let x = 10;");
    testParser("fn add(a: int, b: int) -> int { return a + b; }");
    testParser("let y = 3.14;");

    return 0;
}

