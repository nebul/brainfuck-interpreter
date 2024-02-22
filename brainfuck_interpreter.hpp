#include <string>
#include <vector>
#include <unordered_map>

class BrainfuckInterpreter 
{

public:

    BrainfuckInterpreter(size_t memorySize = 30000);
    void interpret(const std::string& code);

private:

    std::unordered_map<size_t, size_t> mapLoop(const std::string& code);

    std::vector<unsigned char> memory;
    size_t pointer;
    
};
