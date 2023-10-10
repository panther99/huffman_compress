#include "../includes/Parser.hpp"

void Parser::parse()
{
    for (std::string line; std::getline(_file, line); )
    {
        for (char& c : line)
        {
            auto it = _chars_count.find(c);

            if (it == _chars_count.end())
            {
                _chars_count.emplace(c, 1);
                continue;
            }
            
            it->second += 1;
        }
    }
}

size_t Parser::count_of(char c)
{
    auto it = _chars_count.find(c);
    return it == _chars_count.end() ? 0 : it->second;
}
