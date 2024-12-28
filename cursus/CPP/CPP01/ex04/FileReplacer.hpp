#pragma once

#include <iostream>
#include <fstream>
#include <string>

class FileReplacer 
{

    private:

        const std::string _filename;
        const std::string _s1;
        const std::string _s2;
        FileReplacer(void);
        bool readFile(std::string& content);
        bool writeFile(const std::string& content);
        std::string replaceOccurrences(const std::string& content);

    public:
        ~FileReplacer(void);
        FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
        bool replace();
};