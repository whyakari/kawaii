#include "parser.h"
#include <iostream>
#include <stdexcept>

std::string token(TokenType type) {
    switch (type) {
        case TokenType::TOK_KUDASAI: return "TOK_KUDASAI";
        case TokenType::TOK_YAMETE: return "TOK_YAMETE";
        case TokenType::TOK_LPAREN: return "TOK_LPAREN";
        case TokenType::TOK_RPAREN: return "TOK_RPAREN";
        case TokenType::TOK_COLON: return "TOK_COLON";
        case TokenType::TOK_STRING: return "TOK_STRING";
		case TokenType::TOK_INT: return "TOK_INT";
        case TokenType::TOK_LBRACE: return "TOK_LBRACE";
        case TokenType::TOK_RBRACE: return "TOK_RBRACE";
        case TokenType::TOK_SEMICOLON: return "TOK_SEMICOLON";
        case TokenType::TOK_EOF: return "TOK_EOF";
        case TokenType::TOK_IDENTIFIER: return "TOK_IDENTIFIER";
        default:
            return "UNKNOWN";
    }
}

Parser::Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}

void Parser::eat(TokenType type) {
    if (currentToken.type == type) {
        currentToken = lexer.getNextToken();
    } else {
        std::string expectedToken = token(type);
        std::string foundToken = token(currentToken.type);
        throw std::runtime_error("Syntax error: expected token '" + expectedToken + "' but found '" + foundToken + "'");
    }
}

AstNode Parser::parseFunction() {
    AstNode node;
    node.type = "Function";

    // Parse "kudasai" keyword
    token(TokenType::TOK_KUDASAI);

    // Parse function name
    node.name = currentToken.value;
    token(TokenType::TOK_IDENTIFIER);

    // Parse parameter list
    token(TokenType::TOK_LPAREN);
    node.parameterName = currentToken.value;
    token(TokenType::TOK_IDENTIFIER);
    token(TokenType::TOK_COLON);
    node.parameterType = currentToken.value;
    if (currentToken.type == TokenType::TOK_IDENTIFIER) {
        node.parameterType = currentToken.value;
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Syntax error: invalid parameter type");
    }

    token(TokenType::TOK_IDENTIFIER);  // Consume parameter name
    token(TokenType::TOK_RPAREN);  // Consume closing parenthesis

    // Parse "yamete" keyword and return type
    token(TokenType::TOK_YAMETE);
    if (currentToken.type == TokenType::TOK_STRING) {
        node.returnType = "string";
        currentToken = lexer.getNextToken();
    } else if (currentToken.type == TokenType::TOK_INT) {
        node.returnType = "int";
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Syntax error: expected return type but found " + token(currentToken.type));
    }

    eat(TokenType::TOK_IDENTIFIER);  // Consume return type

    // Parse function body (optional for now)
    if (currentToken.type == TokenType::TOK_LBRACE) {
        eat(TokenType::TOK_LBRACE);
        while (currentToken.type != TokenType::TOK_RBRACE && currentToken.type != TokenType::TOK_EOF) {
            // Skip the body for now
            currentToken = lexer.getNextToken();
        }
        eat(TokenType::TOK_RBRACE);  // Consume closing brace
    }

    return node;
}

