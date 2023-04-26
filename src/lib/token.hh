#pragma once
#include <string>

namespace BFE
{
    enum TokenType
    {
        OPERATOR,
        STRING,
        IDENTIFIER,
        MODULE,
        SPECIAL,
        WHITE_SPACE,
        END_OF_FILE
    };

    struct Token
    {
        TokenType type;
        std::string value;
    };

}