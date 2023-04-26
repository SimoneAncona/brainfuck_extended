#include "lexer.hh"

BFE::Lexer::Lexer(std::string content)
{
    this->content = content;
    this->current_index = 0;
    this->current_token_type = WHITE_SPACE;
    this->current_token_value = "";
    this->current_line = 1;
    this->current_column = 1;
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
    this->current_token_type = recognize_token();
    if (this->current_token_type == BFE::TokenType::UNKNOWN)
    {
        BFE::print_error(std::format("Unrecognized token at line {}, column {}", this->current_line, this->current_column));
        exit(1);
    }

    if (this->current_token_type == BFE::TokenType::IDENTIFIER)
    {
        return get_identifier();
    }

    if (this->current_token_type == BFE::TokenType::NUMBER)
    {
        return get_number();
    }

    if (this->current_token_type == BFE::TokenType::STRING)
    {
        return get_string();
    }

    Token token;
    token.type = this->current_token_type;
    token.value = this->content[this->current_index];
    token.column = this->current_column++;
    token.line = this->current_line;

    this->current_index++;

    if (this->current_token_type == NEW_LINE)
    {
        this->current_column = 1;
        this->current_line++;
    }

    return token;
}

BFE::Token BFE::Lexer::get_identifier()
{
    std::string str = "";
    TokenType type = this->current_token_type;
    Token token;
    int init_column = this->current_column;
    int init_line = this->current_line;

    do
    {
        str += this->content[this->current_index];
        current_index++;
        current_column++;
        type = recognize_token();
    } while (
        type == BFE::TokenType::IDENTIFIER || type == BFE::TokenType::NUMBER);

    if (type == NEW_LINE)
    {
        this->current_column = 1;
        this->current_line++;
    }

    token.type = IDENTIFIER;
    token.value = str;
    token.column = init_column;
    token.line = init_line;

    return token;
}

BFE::Token BFE::Lexer::get_number()
{
    std::string str = "";
    TokenType type = this->current_token_type;
    Token token;
    int init_column = this->current_column;
    int init_line = this->current_line;

    do
    {
        str += this->content[this->current_index];
        current_index++;
        current_column++;
        type = recognize_token();
    } while (type == BFE::TokenType::NUMBER);

    token.type = NUMBER;
    token.value = str;
    token.column = init_column;
    token.line = init_line;

    if (type == NEW_LINE)
    {
        this->current_column = 1;
        this->current_line++;
    }

    return token;
}

BFE::Token BFE::Lexer::get_string()
{
    std::string str = "";
    TokenType type = this->current_token_type;
    Token token;
    int init_column = this->current_column;
    int init_line = this->current_line;

    do
    {
        str += this->content[this->current_index];
        current_index++;
        current_column++;
        type = recognize_token();
    } while (
        !(
            type == BFE::TokenType::STRING
            || type == BFE::TokenType::END_OF_FILE
        )
        );

    token.type = STRING;
    token.value = str + "\"";
    token.column = init_column;
    token.line = init_line;

    if (type == NEW_LINE)
    {
        this->current_column = 1;
        this->current_line++;
    }

    this->current_index++;

    return token;
}

BFE::TokenType BFE::Lexer::recognize_token()
{
    char current_char = this->content[this->current_index];
    if (this->specials.find(current_char) != std::string::npos)
        return BFE::SPECIAL;
    if (this->numeric.find(current_char) != std::string::npos)
        return BFE::NUMBER;
    if (current_char == ' ' || current_char == '\t')
        return BFE::WHITE_SPACE;
    if (current_char == '\0')
        return BFE::END_OF_FILE;
    if (current_char == '"')
        return BFE::STRING;
    if (current_char == '\n')
        return BFE::NEW_LINE;
    if (this->id.find(current_char) != std::string::npos)
        return BFE::IDENTIFIER;
    return BFE::UNKNOWN;
}