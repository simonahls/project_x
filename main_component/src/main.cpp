#include <iostream>
#include "FileIO.h"
#include <string>
#include <can_messages/CAN_min_signals.h>

// SOME EXPERIMENTS FOR READING AND WRITING TO OUTPUT.......
// Run command ./main_component ../../main_component/src/input_file.txt

int main(int argc, char *argv[])
{
    std::string set{"set"};
    std::string get{"get"};
    std::string humidity{"humidity"};
    std::string temperature{"temperature"};
    std::cout << "korv" << std::endl;
    FileIO Fileioobj;
    CAN_min_signals can;

    // can.set_humidity(10.5);
    std::cout << can.set_humidity(10.5) << std::endl;

    // This fucntion returns a line of string.
    auto korv{Fileioobj.readLine("input_file.txt")};

    std::cout << korv << std::endl;

    if (korv.find("humidity") == 4)
    {
        std::cout << "call the humidity function!" << std::endl;
    }

    if (korv[0] == set[0])
    {
        std::cout << "CAll the set function" << std::endl;
    }
    if (korv[0] == get[0])
    {
        std::cout << "CAll the get function" << std::endl;
    }

    Fileioobj.writeLine("../../output.txt", Fileioobj.readLine(argv[1]));
    // need to read from a file and execute the command with the help of fileio and can_messages.

    // write to a file with the

    return 0;
}
