#pragma once

#include <vector>
#include <cstddef>
#include "../common/Token.hpp"

class Lexer
{
public: 
Lexer(const std::string& source);
std::vector<Token> Tokenize();

private:

std::string Source;
size_t Position;

char Peek() const;
char Advance();

void SkipWhiteSpace();

Token ReadIdentifier();
Token Readstring();

};

