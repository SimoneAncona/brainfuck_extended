#include "lexer.hh"

BFE::Lexer::Lexer(std::string content)
{
    this->content = content;
    this->current_index = 0;
    this->current_token_type = WHITE_SPACE;
    this->current_token_value = "";
}

BFE::Lexer::~Lexer()
{

}

std::vector<BFE::Token> BFE::Lexer::get_tokens()
{
    std::vector<BFE::Token> tokens;
    while (this->current_token_type != BFE::END_OF_FILE)
    {
        tokens.push_back(get_next_token());
    }
    return tokens;
}

BFE::Token BFE::Lexer::get_next_token()
{
    Token token;

    return token;
}