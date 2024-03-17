#include "../include/lexer.h"
#include <iostream>

std::string tokenTypeToString(TokenType type) {
    switch (type) {
        case TokenType::TOK_EOF: return "TOK_EOF";
        case TokenType::TOK_IDENTIFIER: return "TOK_IDENTIFIER";
        case TokenType::TOK_LPAREN: return "TOK_LPAREN";
        case TokenType::TOK_RPAREN: return "TOK_RPAREN";
        case TokenType::TOK_COLON: return "TOK_COLON";
        case TokenType::TOK_STRING: return "TOK_STRING";
        case TokenType::TOK_LBRACE: return "TOK_LBRACE";
        case TokenType::TOK_RBRACE: return "TOK_RBRACE";
        case TokenType::UNKNOWN_TOKEN: return "UNKNOWN_TOKEN";
        default:
			return "UNKNOWN";
    }
}

void testLexer(const std::string& input) {
    Lexer lexer(input);
    Token token;
    do {
        token = lexer.getNextToken();
        std::cout << "Token type: " << tokenTypeToString(token.type) << ", value: " << token.value << std::endl;
    } while (token.type != TokenType::TOK_EOF);
}

int main() {
    std::string input = "kudasai akari(p: string) yamete {}";
    testLexer(input);
    return 0;
}

