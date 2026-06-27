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
TokenType token; 
std::string text; 

Token(TokenType token, const std::string& text) 
: type(type) 
  text(text) 
{
}

};
