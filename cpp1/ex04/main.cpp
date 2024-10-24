#include <iostream>
#include <fstream>
#include <string>

std::string replaceOccurrence(const std::string& line, const std::string& s1, const std::string& s2) {
    std::string modifiedLine;
    size_t pos = 0;
    size_t start = 0;

    while ((pos = line.find(s1, start)) != std::string::npos)
    {
        modifiedLine += line.substr(start, pos - start);
        modifiedLine += s2;
        start = pos + s1.length();
    }

    modifiedLine += line.substr(start);
    
    return modifiedLine;
}

int main(int ac, char **av)
{
    if (ac == 4) 
    {
        std::string filenameArg = av[1];
        std::string s1 = av[2];
        std::string s2 = av[3];
        std::string line;

        std::ifstream inputFile(filenameArg);
        if (!inputFile)
        {
            std::cerr << "Error: Could not open file [" << filenameArg << "]" << std::endl;
            return 1;
        }

        std::ofstream outputFile(filenameArg + ".replace");
        if (!outputFile)
        {
            std::cerr << "Error: Could not create output file" << std::endl;
            return 1;
        }
        while (getline(inputFile, line)) 
        {
            std::string modifiedLine = replaceOccurrence(line, s1, s2);
            outputFile << modifiedLine << std::endl;
        }
    }
    else
        std::cout << "Usage: " << std::endl << av[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;

    return 0;
}
