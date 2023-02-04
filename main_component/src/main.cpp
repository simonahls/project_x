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
    std::string humidity{"hum"};
    std::string temperature{"tem"};
    FileIO Fileioobj;
    CAN_min_signals can;

    // can.set_humidity(10.5);
    // std::cout << can.set_humidity(10.5) << std::endl;

    // This fucntion returns a line of string.

    auto whole_file{Fileioobj.readLines(argv[1])};
    auto korv{Fileioobj.readLine(argv[1])};

    // In this for loop i get access to one string at a time in the vector.
    for (auto i : whole_file)
    {
        if (i.substr(0, 3) == set)
        {
            if (i.substr(4, 3) == humidity)
            {
                std::cout << "Set dectected, humidety dectected init humidety set_function.... Done!" << std::endl;
                auto value_hum = i.substr(13, (i.length() - 14));
                std::cout << value_hum << "<---printing value!" << std::endl;
            }
            else if (i.substr(4, 3) == temperature)
            {
                std::cout << "Set dectected, temperature dectected init temperature set_function.... Done!" << std::endl;
                auto value_temp = i.substr(16, (i.length() - 17));
                std::cout << value_temp << "<---printing value!" << std::endl;
            }
            else
            {
                // throw error code.
            }
        }
        else if (i.substr(0, 3) == get)
        {

            if (i.substr(4, 3) == humidity)
            {
                std::cout << "get dectected,humidety dectected init get_humidety function.... Done!" << std::endl;
                auto value_hum = i.substr(13, (i.length() - 14));
                std::cout << value_hum << "<---printing value!" << std::endl;
            }
            else if (i.substr(4, 3) == temperature)
            {
                std::cout << "get dectected,temperature dectected init get_temperature function.... Done!" << std::endl;
                auto value_temp = i.substr(16, (i.length() - 17));
                std::cout << value_temp << "<---printing value!" << std::endl;
            }
            else
            {
                // throw error code.
            }
        }
        else
        {
            // throw error code
        }
    }

    // extract one line at a time then next one with for loop.
    // can i return how many lines a file contains(do i need to know)

    // if (korv.substr(0, 3) == set)
    // {

    //     //  std::cout << "Set dectected init set function....\nDone!\n"
    //     //          << std::endl;
    //     // need to know what function to call next set humidety or temperature
    //     if (korv.substr(4, 3) == humidity)
    //     {
    //         std::cout << "Set dectected, humidety dectected init humidety set_function....\nDone!" << std::endl;
    //         auto value_hum = korv.substr(13, 10);
    //         std::cout << value_hum << "<---printing value!" << std::endl;
    //     }
    //     if (korv.substr(4, 3) == temperature)
    //     {

    //         std::cout << "Set dectected, temperature dectected init temperature set_function....\nDone!" << std::endl;
    //         auto value_temp = korv.substr(16, 10);
    //         std::cout << value_temp << "<---printing value!" << std::endl;
    //     }
    // }
    // else if (korv.substr(0, 3) == get)
    // {

    //     // std::cout << "get dectected init get function....\nDone!\n"
    //     //           << std::endl;
    //     if (korv.substr(4, 3) == humidity)
    //     {
    //         std::cout << "get dectected,humidety dectected init get_humidety function....\nDone!" << std::endl;
    //         auto value_hum = korv.substr(13, 10);
    //         std::cout << value_hum << "<---printing value!" << std::endl;
    //     }
    //     if (korv.substr(4, 3) == temperature)
    //     {
    //         std::cout << "get dectected,temperature dectected init get_temperature function....\nDone!" << std::endl;
    //         auto value_temp = korv.substr(16, 10);
    //         std::cout << value_temp << "<---printing value!" << std::endl;
    //     }
    // }

    // std::cout << korv.substr(0, 3) << std::endl;

    // if (korv.find("humidity") == 4)
    // {
    //     std::cout << "call the humidity function!" << std::endl;
    // }

    // if (korv[0] == set[0])
    // {
    //     std::cout << "CAll the set function" << std::endl;
    // }
    // if (korv[0] == get[0])
    // {
    //     std::cout << "CAll the get function" << std::endl;
    // }

    Fileioobj.writeLine("../../output.txt", Fileioobj.readLine(argv[1]));
    // need to read from a file and execute the command with the help of fileio and can_messages.

    // write to a file with the

    return 0;
}
