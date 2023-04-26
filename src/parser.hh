#pragma once
#include "token.hh"
#include <vector>
#include "symbol.hh"

namespace BFE
{
    class Parser
    {
    private:
    public:
        Parser();
        ~Parser();

        std::vector<Symbol> parse();
    };
}