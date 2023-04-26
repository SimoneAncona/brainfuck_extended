#pragma once
#include <string>

namespace BFE
{
    enum InstructionType
    {
        CALL,   // Call a routine
        RET,    // Return from routine
        BASIC,  // Basic instructions such as + - > <
        LOOP,
    };

    struct Instruction
    {
        InstructionType type;
        std::string value;
    };
    
}