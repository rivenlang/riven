#pragma once 
#include <string>

enum class TokenType
{

FTN, 
MAIN, 

LEFT_BRACKET,
RIGHT_BRACKET, 

LEFT_BRACE,
RIGHT_BRACE, 

IMPR, 
OUTPUT, 

STRING, 
SEMICOLON, 
END_OF_FILE, 


};


struct Token 
{
TokenType r_type;
std::string r_text;

Token(TokenType Tokentype, const std::string& text)
: r_text(text), 
  r_type(Tokentype) 
{
}

};
