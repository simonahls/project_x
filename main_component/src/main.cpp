#include <iostream>
#include "FileIO.h"
#include <string>
#include <can_messages/CAN_min_signals.h>
#include <map>

// SOME EXPERIMENTS FOR READING AND WRITING TO OUTPUT.......
// Run command ./main_component ../../main_component/src/input_file.txt

int main(int argc, char *argv[])
{
    CAN_min_signals can;
    FileIO Fileioobj;
    std::string array_func[] = {"set", "get"};
    std::string array_name[] = {"humidety", "temperature"};
    // std::string set{"set"};
    // std::string get{"get"};
    // std::string humidity{"hum"};
    // std::string temperature{"tem"};
    std::string output_string{};
    bool flag{true};

    auto whole_file{Fileioobj.readLines(argv[1])};
    auto korv{Fileioobj.readLine(argv[1])};

    for (std::string string : whole_file)
    {
        int counter{0};
        size_t position_of_value{0};
        std::string value{};

        for (int i = 0; i < sizeof(array_func) / sizeof(array_func[0]); i++)
        {
            for (int j = 0; j < sizeof(array_name) / sizeof(array_name[0]); j++)
            {
                counter++;
                if (string.find(array_func[i]) != std::string::npos && string.find(array_name[j]) != std::string::npos)
                {

                    position_of_value = string.find(array_name[j]) + array_name[j].length() + 1;
                    value = string.substr(position_of_value, string.length() - position_of_value);
                    std::cout << array_func[i] << " " << array_name[j] << " " << value << std::endl;

                    if (flag == true)
                    {
                        output_string = "{\n\t[\n";
                    }
                    flag = false;
                    switch (counter)
                    {
                    case 1:
                        output_string += "\t\t";
                        output_string += can.set_humidity(std::stoi(value));
                        break;
                    case 2:
                        output_string += "\t\t";
                        output_string += can.set_temperature(std::stof(value));
                        break;
                    case 4:
                        output_string += "\t\t";
                        output_string += can.get_temperature();
                        break;
                    case 3:
                        output_string += "\t\t";
                        output_string += can.get_humidity();
                        break;
                    default:
                        break;
                    }

                    output_string += ",";
                    output_string += "\n";
                    break;
                }
            }
        }

        counter = 0;

        // if (string.substr(0, 3) == set)
        // {

        //     // first we need the
        //     // delimiter will be " " i want the index of that one and send it in a for loop to itterate over the string

        //     if (string.substr(4, 3) == humidity)
        //     {
        //         std::cout << "Set dectected, humidety dectected init humidety set_function.... Done!" << std::endl;
        //         auto value_hum = string.substr(13, (string.length() - 14));
        //         std::cout << value_hum << "<---printing value!" << std::endl;
        //     }
        //     else if (string.substr(4, 3) == temperature)
        //     {
        //         std::cout << "Set dectected, temperature dectected init temperature set_function.... Done!" << std::endl;
        //         auto value_temp = string.substr(16, (string.length() - 17));
        //         std::cout << value_temp << "<---printing value!" << std::endl;
        //     }
        //     else
        //     {
        //         // throw error code.
        //     }
        // }
        // else if (string.substr(0, 3) == get)
        // {

        //     if (string.substr(4, 3) == humidity)
        //     {
        //         std::cout << "get dectected,humidety dectected init get_humidety function.... Done!" << std::endl;
        //         auto value_hum = string.substr(13, (string.length() - 14));
        //         std::cout << value_hum << "<---printing value!" << std::endl;
        //     }
        //     else if (string.substr(4, 3) == temperature)
        //     {
        //         std::cout << "get dectected,temperature dectected init get_temperature function.... Done!" << std::endl;
        //         auto value_temp = string.substr(16, (string.length() - 17));
        //         std::cout << value_temp << "<---printing value!" << std::endl;
        //     }
        //     else
        //     {
        //         // throw error code.
        //     }
        // }
        // else
        // {
        //     // throw error code
        // }
    }

    output_string += "\t]\n}";
    std::cout << output_string << std::endl;

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
