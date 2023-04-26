#pragma once
#include "token.hh"
#include <vector>
#include "symbol.hh"

namespace BFE
{
    class Parser
    {
    private:
        std::vector<Token> tokens;

        int current_index;
    public:
        Parser(std::vector<Token>&);
        ~Parser();

        std::vector<Symbol> parse();
    };
}