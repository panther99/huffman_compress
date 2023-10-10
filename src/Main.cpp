#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char* argv[])
{
    if (argv[1] == nullptr)
    {
        std::cerr << "You need to provide a file name.\n";
        return 1;
    }

    std::string file_path = argv[1];

    if (!std::filesystem::exists(file_path))
    {
        std::cerr << "Given file path is invalid or the file does not exist.\n";
        return 1;
    }

    std::ifstream file(file_path);
    std::map<char, size_t> chars_count;

    for (std::string line; std::getline(file, line); )
    {
        for (char& c : line)
        {
            auto it = chars_count.find(c);

            if (it == chars_count.end())
            {
                chars_count.emplace(c, 1);
                continue;
            }
            
            it->second += 1;
        }
    }

    for (auto const& char_count : chars_count)
    {
        std::cout << char_count.first << ": " << char_count.second << "\n";
    }
}
