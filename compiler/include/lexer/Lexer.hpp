#pragma once

#include <string>
#include <vector>
#include <cstddef>
#include "../common/Token.hpp"

class Lexer
{
public: 
Lexer(const std::string& source);
std::vector<Token> tokenize();

private:

std::string r_Source;
size_t r_Position;
size_t line, 
size_t coloumn, 

char Peek() const;
char Advance();
char previous();
char isatend();

void SkipWhiteSpace();

Token ReadIdentifier();
Token ReadString();
Token ReadOperator();

Token NextToken();
};

