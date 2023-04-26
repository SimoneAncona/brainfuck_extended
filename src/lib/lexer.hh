#pragma once
#include <string>
#include <vector>
#include "token.hh"
#include "error.hh"

namespace BFE
{
    class Lexer
    {
    private:
        int current_index;
        TokenType current_token_type;
        std::string current_token_value;
        std::string content;
        int current_line;
        int current_column;

        const std::string specials = "!$@#[]<>+-.:,;&*()";
        const std::string numeric = "0123456789";
        const std::string id = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

        Token get_next_token();
        Token get_identifier();
        Token get_string();
        Token get_number();
        TokenType recognize_token();
        void update_token(TokenType, std::string&);

    public:
        Lexer(std::string);
        ~Lexer();
        std::vector<Token> get_tokens();
    };   
}