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

char Peek() const;
char Advance();

void SkipWhiteSpace();

Token ReadIdentifier();
Token ReadString();

};

