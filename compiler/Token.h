#pragma once 

#include<string>


enum class TokenType
{
RIVEN, 
MAIN, 

LEFT_BRACKET, 
RIGHT_BRACKET, 

LEFT_BRACE,
RIGHT_BRACE, 

IMPR, 
OUTPUT, 

STRING, 
SEMICOLON, 

EOF, 


};


struct Token 
{
TokenType Token, 
std::string text, 

token(const std::string& text) 
: Type(type) 
  Text(text) 


};
