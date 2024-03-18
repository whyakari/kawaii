#include "lexer.h"
#include "../include/lexer.h"
#include <stdexcept>

Lexer::Lexer(const std::string& source) : sourceCode(source), currentPosition(0), currentChar(source[0]) {}

void Lexer::advance() {
    currentPosition++;
    if (currentPosition < sourceCode.size()) {
        currentChar = sourceCode[currentPosition];
    } else {
        currentChar = '\0'; // End of file
    }
}

Token Lexer::getNextToken() {
    while (currentChar != '\0') {

		if (currentChar == '-') {
		    advance();
	        if (currentChar == '>') {
		        advance();
	            return {TokenType::ARROW, "->"};
			}
	    }

        if (isspace(currentChar)) {
            skipWhitespace();
            continue;
        } else if (isalpha(currentChar)) {
            return processIdentifier();
        } else if (isdigit(currentChar)) {
            return processNumber();
        } else {
            switch (currentChar) {
                case '+': advance(); return Token{TokenType::PLUS, "+"};
				case '-': advance(); return Token{TokenType::MINUS, "-"};
                case '*': advance(); return Token{TokenType::TIMES, "*"};
                case '/': advance(); return Token{TokenType::DIVIDE, "/"};
                case ';': advance(); return Token{TokenType::SEMICOLON, ";"};
				case ':': advance(); return Token{TokenType::COLON, ":"};
                case '=': advance(); return Token{TokenType::ASSIGN, "="};
                case '(': advance(); return Token{TokenType::LPAREN, "("};
                case ')': advance(); return Token{TokenType::RPAREN, ")"};
                case '{': advance(); return Token{TokenType::LBRACE, "{"};
                case '}': advance(); return Token{TokenType::RBRACE, "}"};
                case ',': advance(); return Token{TokenType::COMMA, ","};
                default:
                    advance();
                    return Token{TokenType::INVALID, ""};
            }
        }
    }
    return Token{TokenType::EOF_TOKEN, ""}; // End of file
}

Token Lexer::processIdentifier() {
    std::string lexeme;
    while (isalnum(currentChar) || currentChar == '_') {
        lexeme += currentChar;
        advance();
    }

    if (lexeme == "let") {
        return Token{TokenType::LET, lexeme};
    } else if (lexeme == "fn") {
        return Token{TokenType::FUNCTION, lexeme};
    } else if (lexeme == "int") {
        return Token{TokenType::INTEGER, lexeme};
    } else if (lexeme == "float") {
        return Token{TokenType::FLOAT, lexeme};
    } else {
        return Token{TokenType::IDENTIFIER, lexeme};
    }
}


Token Lexer::processNumber() {
    std::string number;
    while (isdigit(currentChar)) {
        number += currentChar;
        advance();
    }
    if (currentChar == '.') {
        number += currentChar;
        advance();
        while (isdigit(currentChar)) {
            number += currentChar;
            advance();
        }
        return Token{TokenType::FLOAT, number};
    } else {
        return Token{TokenType::INTEGER, number};
    }
}

void Lexer::skipWhitespace() {
    while (currentChar != '\0' && isspace(currentChar)) {
        advance();
    }
}

