#include <fstream>
#include <string>
#include <map>

class Parser
{
private:
    std::ifstream& _file;
    std::map<char, size_t> _chars_count;

public:
    Parser(std::ifstream& file) : _file(file) {}

    ~Parser()
    {
        if (_file.is_open())
            _file.close();
    }

    void parse();
    size_t count_of(char c);
};
