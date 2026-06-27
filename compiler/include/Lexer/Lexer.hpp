#pragma once

#include "../common/Token.h"

class Lexer
{
public: 
Lexer(const std::string& source) 
std::vector<Token>Tokenize();

private:

std::string Source;
size_t Position;

char Peek() const;
char Advance();

void SkipWhiteSpace();

Token ReadIndentifier();
Token Readstring();

};

