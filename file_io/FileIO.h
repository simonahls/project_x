#include <fstream>
#include <string>
#include <vector>

class FileIO
{
public:
    // Read a single line from a file and return it as a string
    std::string readLine(const std::string &fileName)
    {
        // create the var line with std::String.
        std::string line;

        // open the file with ifstream.
        std::ifstream file(fileName);

        // Get the line from the file. store it in line.
        std::getline(file, line);
        return line;
    }

    // Read all lines from a file and return them as a vector of strings
    std::vector<std::string> readLines(const std::string &fileName)
    {
        std::vector<std::string> lines;
        // create the vector lines.
        std::string line;
        // create the var line.
        std::ifstream file(fileName);
        // open the file
        while (std::getline(file, line))
        {
            lines.push_back(line);
        }
        // while getline is true then push line to the vector.
        return lines;
    }

    // Write a single line to a file
    void writeLine(const std::string &fileName, const std::string &line)
    {
        std::ofstream file(fileName);
        // open the file
        file << line << std::endl;
        // write to the file
    }

    // Write a vector of lines to a file
    void writeLines(const std::string &fileName, const std::vector<std::string> &lines)
    {
        std::ofstream file(fileName);
        // open the file
        for (const auto &line : lines)
        {
            file << line << std::endl;
        }
        // write to file for each line in lines.
    }
};