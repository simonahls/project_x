#include <iostream>
#include "FileIO.h"
//

int main(void)

{
    // create an instance of FileIO
    FileIO fileIO;

    // Function call to write a single line to the outpuit file.
    std::string writeLine = "will be overwriten";
    fileIO.writeLine("data.txt", writeLine);

    // function call to write multiply lines to file.
    std::vector<std::string> writelines = {"I love fanny", "Do you want candy?"};
    fileIO.writeLines("data.txt", writelines);

    // Function call to read a single line from spec file.
    std::string readLine = fileIO.readLine("data.txt");
    std::cout << "Read Line: " << readLine << std::endl;

    // Funciton call to read multiply lines of text from spec file.
    std::vector<std::string> readlines = fileIO.readLines("data.txt");
    std::cout << "read lines: " << std::endl;
    for (const auto &line : readlines)
        std::cout << line << std::endl;

    return 0;
}