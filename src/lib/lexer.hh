#pragma once
#include <string>
#include <vector>
#include "token.hh"

namespace BFE
{
    class Lexer
    {
    private:
        int current_index;
        TokenType current_token_type;
        std::string current_token_value;
        std::string content;

        Token get_next_token();

    public:
        Lexer(std::string);
        ~Lexer();
        std::vector<Token> get_tokens();
    };   
}