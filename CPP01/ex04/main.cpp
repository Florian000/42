#include "FileReplacer.hpp"

int main(int argc, char* argv[])
{
    if (argc != 4)    
        return (std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl, 1);

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    FileReplacer filereplacer(filename, s1, s2);

    if (s1.empty())
        return (std::cerr << "Error: s1 cannot be an empty string." << std::endl, 1);

    if (!filereplacer.replace())
        return (1);
    return (0);
}