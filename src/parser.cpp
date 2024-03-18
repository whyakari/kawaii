#include "parser.h"
#include <iostream>
#include <stdexcept>

Parser::Parser(Lexer& lexer) : lexer(lexer), currentToken(lexer.getNextToken()) {}

void Parser::parse() {
    statement();
}

void Parser::eat(TokenType type) {
    if (currentToken.type == type) {
        currentToken = lexer.getNextToken();
    } else {
        throw std::runtime_error("Syntax error: unexpected token");
    }
}

void Parser::statement() {
    if (currentToken.type == TokenType::LET) {
        eat(TokenType::LET);
        eat(TokenType::IDENTIFIER);
        eat(TokenType::ASSIGN);
        expression();
        eat(TokenType::SEMICOLON);
    } else if (currentToken.type == TokenType::RETURN) {
        eat(TokenType::RETURN);
        expression();
        eat(TokenType::SEMICOLON);
    } else if (currentToken.type == TokenType::FUNCTION) {
        functionDeclaration();
    } else {
        throw std::runtime_error("Syntax error: invalid statement");
    }
}

void Parser::expression() {
    if (currentToken.type == TokenType::INTEGER || currentToken.type == TokenType::FLOAT || currentToken.type == TokenType::IDENTIFIER) {
        eat(currentToken.type);
    } else if (currentToken.type == TokenType::LPAREN) {
        eat(TokenType::LPAREN);
        expression();
        eat(TokenType::RPAREN);
    } else if (currentToken.type == TokenType::FUNCTION) {
        eat(TokenType::FUNCTION);
        eat(TokenType::IDENTIFIER); // Nome da função
        eat(TokenType::LPAREN);
        while (currentToken.type != TokenType::RPAREN) {
            expression();
            if (currentToken.type == TokenType::COMMA) {
                eat(TokenType::COMMA);
            } else if (currentToken.type != TokenType::RPAREN) {
                throw std::runtime_error("Syntax error: unexpected token in function parameters");
            }
        }
        eat(TokenType::RPAREN);
        eat(TokenType::ARROW);
        eat(TokenType::IDENTIFIER); // Tipo de retorno da função
        eat(TokenType::LBRACE);
        while (currentToken.type != TokenType::RBRACE) {
            expression();
        }
        eat(TokenType::RBRACE);
    } else {
        throw std::runtime_error("Syntax error: unexpected token in expression");
    }

    while (currentToken.type == TokenType::PLUS || currentToken.type == TokenType::MINUS || currentToken.type == TokenType::TIMES || currentToken.type == TokenType::DIVIDE) {
        eat(currentToken.type);
        expression();
    }
}

void Parser::functionDeclaration() {
    eat(TokenType::FUNCTION);
    eat(TokenType::IDENTIFIER); // Nome da função
    eat(TokenType::LPAREN);
    while (currentToken.type != TokenType::RPAREN) {
        eat(TokenType::IDENTIFIER); // Tipo do parâmetro
        if (currentToken.type == TokenType::COMMA) {
            eat(TokenType::COMMA);
        }
    }
    eat(TokenType::RPAREN);
    eat(TokenType::ARROW); // Token "->" para indicar tipo de retorno
    eat(TokenType::IDENTIFIER); // Tipo de retorno da função
    eat(TokenType::LBRACE);
    while (currentToken.type != TokenType::RBRACE) {
        statement();
    }
    eat(TokenType::RBRACE);
}

