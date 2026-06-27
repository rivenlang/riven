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
TokenType r_token;
std::string r_text;

Token(TokenType Tokentype, const std::string& Tokentext)
: r_text(Tokentext) 
  r_token(Tokentype) 
{
}

};
