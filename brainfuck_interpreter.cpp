#include <iostream>
#include <stack>

#include "brainfuck_interpreter.hpp"

BrainfuckInterpreter::BrainfuckInterpreter(size_t memorySize) : 
memory(memorySize, 0), 
pointer(0) 
{
}

void BrainfuckInterpreter::interpret(const std::string& code) 
{
    std::unordered_map<size_t, size_t> loopMapping = mapLoop(code);
    for (size_t pc = 0; pc < code.size(); ++pc) 
    {
        switch (code[pc]) 
        {
            case '>': ++pointer; break;
            case '<': --pointer; break;
            case '+': ++memory[pointer]; break;
            case '-': --memory[pointer]; break;
            case '.': std::cout << memory[pointer]; break;
            case ',': std::cin >> memory[pointer]; break;
            case '[': if (!memory[pointer]) pc = loopMapping[pc]; break;
            case ']': if (memory[pointer]) pc = loopMapping[pc]; break;
            default : break;
        }
    }
}


std::unordered_map<size_t, size_t> BrainfuckInterpreter::mapLoop(const std::string& code) 
{
    std::unordered_map<size_t, size_t> loopMapping;
    std::stack<size_t> loopStack;

    for (size_t i = 0; i < code.size(); ++i)
    {
        if (code[i] == '[') 
        {
            loopStack.push(i);
        }
        else if (code[i] == ']') 
        {
            size_t start = loopStack.top();
            loopStack.pop();
            loopMapping[start] = i;
            loopMapping[i] = start;
        }
    }

    return loopMapping;
}
