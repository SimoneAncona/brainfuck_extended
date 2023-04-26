#pragma once
#include <string>

namespace BFE
{
    enum TokenType
    {
        STRING,
        IDENTIFIER,
        MODULE,
        SPECIAL,
        NUMBER,
        WHITE_SPACE,
        NEW_LINE,
        END_OF_FILE,
        UNKNOWN
    };

    struct Token
    {
        TokenType type;
        std::string value;
        int line;
        int column;
    };

}