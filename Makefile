CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -I ./include/

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests
BUILD_DIR = build
BIN_DIR = bin

LEXER_SRC = $(SRC_DIR)/lexer.cpp
PARSER_SRC = $(SRC_DIR)/parser.cpp
CODEGEN_SRC = $(SRC_DIR)/codegen.cpp
MAIN_SRC = main.cpp

LEXER_OBJ = $(BUILD_DIR)/lexer.o
PARSER_OBJ = $(BUILD_DIR)/parser.o
CODEGEN_OBJ = $(BUILD_DIR)/codegen.o
MAIN_OBJ = $(BUILD_DIR)/main.o

LEXER_TEST_SRC = $(TEST_DIR)/test_lexer.cpp
PARSER_TEST_SRC = $(TEST_DIR)/test_parser.cpp
CODEGEN_TEST_SRC = $(TEST_DIR)/test_codegen.cpp

LEXER_TEST_BIN = $(BIN_DIR)/test_lexer
PARSER_TEST_BIN = $(BIN_DIR)/test_parser
CODEGEN_TEST_BIN = $(BIN_DIR)/test_codegen
KAWAIILANG_BIN = $(BIN_DIR)/kawaiiLang

.PHONY: all clean help

all: $(KAWAIILANG_BIN)

$(KAWAIILANG_BIN): $(LEXER_OBJ) $(PARSER_OBJ) $(CODEGEN_OBJ) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(LEXER_OBJ): $(LEXER_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(PARSER_OBJ): $(PARSER_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(CODEGEN_OBJ): $(CODEGEN_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(MAIN_OBJ): $(MAIN_SRC)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

help:
	@echo "Available targets:"
	@echo "  all         : Build the kawaiiLang compiler"
	@echo "  test_lexer  : Build and run the lexer tests"
	@echo "  test_parser : Build and run the parser tests"
	@echo "  test_codegen: Build and run the codegen tests"
	@echo "  clean       : Remove all built files"

test_lexer: $(LEXER_OBJ) $(LEXER_TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(LEXER_TEST_BIN) $^

test_parser: $(LEXER_OBJ) $(PARSER_OBJ) $(PARSER_TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(PARSER_TEST_BIN) $^

test_codegen: $(LEXER_OBJ) $(PARSER_OBJ) $(CODEGEN_OBJ) $(CODEGEN_TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(CODEGEN_TEST_BIN) $^

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

