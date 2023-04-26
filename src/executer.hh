#pragma once
#include "instruction.hh"
#include <string>
#include <vector>

namespace BFE
{
    class Executer
    {
        private:
            int call_routine();
        public:
            Executer(std::vector<Instruction>&);
            ~Executer();
    };
}