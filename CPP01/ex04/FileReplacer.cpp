#include "FileReplacer.hpp"
#include <fstream>
#include <iostream>


FileReplacer::FileReplacer(void)
{
    return ; 
}

FileReplacer::~FileReplacer(void)
{
    return ; 
}

FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2): _filename(filename), _s1(s1), _s2(s2)
{
    return ; 
}

bool FileReplacer::replace()
{
    std::string content;
    if (!readFile(content))
        return (false);

    std::string replacedContent = replaceOccurrences(content);

    if (!writeFile(replacedContent))
        return (false);
    return (true);
}

bool FileReplacer::readFile(std::string& content)
{
    std::ifstream inputFile(this->_filename.c_str());
    if (!inputFile.is_open())
        return (std::cerr << "Error: Could not open file " << this->_filename << std::endl, false);

    std::string line;

    while (std::getline(inputFile, line))
        content += line + "\n";

    inputFile.close();
    return (true);
}

bool FileReplacer::writeFile(const std::string& content)
{
    std::ofstream outputFile((this->_filename + ".replace").c_str());

    if (!outputFile.is_open())
        return (std::cerr << "Error: Could not open file " << this->_filename << ".replace" << std::endl, false);

    outputFile << content;
    outputFile.close();
    return (true);
}

std::string FileReplacer::replaceOccurrences(const std::string& content)
{
    std::string result;
    size_t pos = 0;
    size_t foundPos;

    while ((foundPos = content.find(_s1, pos)) != std::string::npos)
    {
        result.append(content, pos, foundPos - pos);
        result.append(_s2);
        pos = foundPos + _s1.length();
    }

    result.append(content, pos, std::string::npos);
    return (result);
}
