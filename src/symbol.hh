#pragma once
#include <string>
#include <vector>
#include "instruction.hh"

namespace BFE
{
    struct Symbol
    {
        std::string name;
        std::vector<Instruction> instructions;
    };
}