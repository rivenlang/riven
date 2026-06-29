#pragma once

#include <string>
#include <vector>
#include <cstddef>
#include "../common/Token.hpp"

class Lexer
{
public: 
Lexer(const std::string& source);
std::vector<Token> Tokenize();

private:

std::string r_Source;

size_t r_Position, r_line, r_coloumn;

char Peek() const;
char Advance();
char Previous();

bool IsAtEnd() const;

void SkipWhiteSpace();

Token ReadIdentifier();
Token ReadString();
Token ReadOperator();

Token NextToken();
};

