#include "../include/lexer.h"

Lexer::Lexer(const std::string& input) : input(input), position(0), currentChar(input[0]) {}

void Lexer::advance() {
    position++;
    if (position < input.length()) {
        currentChar = input[position];
    } else {
        currentChar = '\0';
    }
}

void Lexer::skipWhitespace() {
    while (currentChar != '\0' && isspace(currentChar)) {
        advance();
    }
}

Token Lexer::parseIdentifier() {
    std::string result;
    while (currentChar != '\0' && isalnum(currentChar)) {
        result += currentChar;
        advance();
    }
    return {TokenType::TOK_IDENTIFIER, result};
}

Token Lexer::parseString() {
    advance();  // Skip the opening quote
    std::string result;
    while (currentChar != '"' && currentChar != '\0') {
        result += currentChar;
        advance();
    }
    advance();  // Skip the closing quote
    return {TokenType::TOK_STRING, result};
}

Token Lexer::parseNumber() {
    std::string result;
    while (currentChar != '\0' && isdigit(currentChar)) {
        result += currentChar;
        advance();
    }
    return {TokenType::TOK_NUMBER, result};
}


Token Lexer::getNextToken() {
    while (currentChar != '\0') {
        if (isspace(currentChar)) {
            skipWhitespace();
            continue;
        }
        if (isalpha(currentChar)) {
            return parseIdentifier();
        }
        if (isdigit(currentChar)) {
            return parseNumber();
        }
        if (currentChar == '"') {
            return parseString();
        }
        switch (currentChar) {
            case '(':
                advance();
                return {TokenType::TOK_LPAREN, "("};
            case ')':
                advance();
                return {TokenType::TOK_RPAREN, ")"};
            case ':':
                advance();
                return {TokenType::TOK_COLON, ":"};
            case '{':
                advance();
                return {TokenType::TOK_LBRACE, "{"};
            case '}':
                advance();
                return {TokenType::TOK_RBRACE, "}"};
            case ';':
                advance();
                return {TokenType::TOK_SEMICOLON, ";"};
            default:
                return {TokenType::TOK_EOF, ""};
        }
    }
    return {TokenType::TOK_EOF, ""};
}

