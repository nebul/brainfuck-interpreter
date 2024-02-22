#include "brainfuck_interpreter.hpp"

int main() 
{
    BrainfuckInterpreter brainfuckInterpreter;
    brainfuckInterpreter.interpret("++++++++++[>+>+++>+++++++>++++++++++<<<<-]>>>----.>++++++++++++++.-----------------.++++++++.+++++.--------.+++++++++++++++.------------------.++++++++.");
    return 0;
}
