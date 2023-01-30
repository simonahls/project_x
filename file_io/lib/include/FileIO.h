#include <fstream>
#include <string>
#include <vector>
#include <iostream>

class FileIO
{

public:
    FileIO() {}

    // Read a single line from a file and return it as a string
    std::string readLine(const std::string &fileName);

    // Read all lines from a file and return them as a vector of strings
    std::vector<std::string> readLines(const std::string &fileName);

    // Write a single line to a file
    void writeLine(const std::string &fileName, const std::string &line);

    // Write a vector of lines to a file
    void writeLines(const std::string &fileName, const std::vector<std::string> &lines);
};