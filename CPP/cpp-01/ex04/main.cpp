#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

std::string _replace(const std::string& content, const std::string& s1, const std::string& s2)
{
    if (s1.empty())
        return content;
    
    std::string result;
    size_t pos = 0;
    size_t found = 0;
    
    while ((found = content.find(s1, pos)) != std::string::npos)
    {
        result += content.substr(pos, found - pos);
        result += s2;
        pos = found + s1.length();
    }
    result += content.substr(pos);
    return result;
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
    
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty" << std::endl;
        return 1;
    }
    
    std::ifstream inputFile(filename.c_str());
    if (!inputFile.is_open())
    {
        std::cerr << "Error: Cannot open file '" << filename << "'" << std::endl;
        return 1;
    }
    
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string content = buffer.str();
    
    inputFile.close();
    
    std::string replacedContent = _replace(content, s1, s2);
    
    std::string outputFilename = filename + ".replace";
    std::ofstream outputFile(outputFilename.c_str());
    if (!outputFile.is_open())
    {
        std::cerr << "Error: Cannot create output file '" << outputFilename << "'" << std::endl;
        return 1;
    }
    
    outputFile << replacedContent;
    outputFile.close();
    
    std::cout << "File processed successfully. Output written to '" << outputFilename << "'" << std::endl;
    return 0;
}