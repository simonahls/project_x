#include <iostream>
#include "FileIO.h"
#include <string>
#include <can_messages/CAN_signals_biglist.h>
#define FIND_MATCH string.find(array_func[i]) != std::string::npos &&string.find(array_name[j]) != std::string::npos

// Run command ./main_component ../../main_component/src/input_file.txt

int main(int argc, char *argv[])
{
    CAN_signals_biglist can;
    FileIO Fileioobj;

    // here we store the values we want to search for if they match with any functions.
    // Its setup and needs one match for each array to get a match.
    // If we want to add functionality to the script. Insert function in array_func array.
    // And match it with function array_name
    std::string array_func[] = {"set", "get"};
    std::string array_name[] = {"humidety", "temperature"};

    std::string output_string{};
    bool flag{true};
    bool found_match = false;

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
                if (FIND_MATCH)
                {
                    // std::cout << __FUNCTION__ << " : " << __LINE__ << std::endl;
                    position_of_value = string.find(array_name[j]) + array_name[j].length() + 1;
                    value = string.substr(position_of_value, string.length() - position_of_value);
                    // std::cout << array_func[i] << " " << array_name[j] << " " << value << std::endl;
                    found_match = true;
                    if (flag == true)
                    {
                        output_string = "{\n\t[\n";
                    }
                    flag = false;
                    // switch work from the counter and the sequens of the array.
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
        if (found_match == false)
        {
            output_string += "\t\t";
            output_string += "Not yet implemented";
            output_string += "\n";
        }
        found_match = false;

        counter = 0;
    }

    output_string += "\t]\n}";
    Fileioobj.writeLine("../../output.txt", output_string);

    return 0;
}
