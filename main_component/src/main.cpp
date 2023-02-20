#include <iostream>
#include "FileIO.h"
#include <string>
#include <vector>
#include <can_messages/CAN_signals_biglist.h>
#define FIND_MATCH string.find(array_func[i]) != std::string::npos &&string.find(array_name[j]) != std::string::npos

// Run command ./main_component ../../main_component/src/commands_biglist.txt

int main(int argc, char *argv[])
{

    CAN_signals_biglist can;
    FileIO Fileioobj;

    std::string array_func[] = {"get", "set"};
    std::string array_name[] = {"temperature", "humidity", "front_sensor_status", "flow_rate", "flow_meter_sensor_status", "light_intensity", "light_intensity_sensor_status", "water_level", "water_level_sensor_status", "soil_moisture", "soil_moisture_sensor_status", "stop_signal_light"};
    std::string array_name_uint8_t[] = {"humidity", "flow_meter_sensor_status", "light_intensity", "light_intensity_sensor_status", "water_level", "water_level_sensor_status", "soil_moisture", "soil_moisture_sensor_status"};
    std::string array_name_uint16_t[] = {"flow_rate"};
    std::string array_name_float[] = {"temperature"};
    std::string array_name_bool[] = {"front_sensor_status", "stop_signal_light"};

    int number_of_commands{0};
    std::string output_string{};
    bool flag{true};
    bool found_match = false;

    auto whole_file{Fileioobj.readLines(argv[1])};
    auto korv{Fileioobj.readLine(argv[1])};

    int function_selector{0};

    for (std::string string : whole_file)
    {
        function_selector = 0;
        int get_counter = 0;
        int set_uint8_counter = 0;
        int set_uint16_counter = 0;
        int set_float_counter = 0;
        int set_bool_counter = 0;

        uint8_t value_uint8_t{0};
        uint16_t value_uint16_t{0};
        float value_float{0};
        bool value_bool = false;
        size_t position_of_value{0};
        std::string value{};

        // this will react to substring and not exactly match. No time for implementaion
        for (int j = 0; j < sizeof(array_name) / sizeof(array_name[0]); j++)
        {
            std::size_t found_name = string.find(array_name[j], 0);
            std::size_t found_func = string.find(array_func[0], 0);

            if (found_name != std::string::npos && found_func != std::string::npos)
            {
                std::cout << "iam no arg" << std::endl;
                function_selector = 1;
                found_match = true;
                if (flag == true)
                {
                    output_string += "{\n\t[\n";
                }
                flag = false;
                break;
            }

            get_counter += 1;
        }
        // this will react to substring and not exactly match. No time for implementaion
        for (int j = 0; j < sizeof(array_name_uint8_t) / sizeof(array_name_uint8_t[0]); j++)
        {
            std::size_t found_name = string.find(array_name_uint8_t[j], 0);
            std::size_t found_func = string.find(array_func[1], 0);
            if (found_name != std::string::npos && found_func != std::string::npos)
            {

                function_selector = 2;
                found_match = true;
                position_of_value = string.find(array_name_uint8_t[j], 0) + array_name_uint8_t[j].length() + 1;
                value = string.substr(position_of_value, string.length() - position_of_value);
                std::cout << position_of_value << "posistion of value" << std::endl;
                std::cout << "before converstion uint8 = |" << value << "|" << std::endl;
                value_uint8_t = atoi(value.c_str());
                std::cout << "|" << value_uint8_t << "| iam value_uint8_t" << std::endl;
                if (flag == true)
                {
                    output_string += "{\n\t[\n";
                }
                flag = false;
                break;
            }
            set_uint8_counter++;
        }

        for (int j = 0; j < sizeof(array_name_uint16_t) / sizeof(array_name_uint16_t[0]); j++)
        {
            std::size_t found_name = string.find(array_name_uint16_t[j], 0);
            std::size_t found_func = string.find(array_func[1], 0);
            if (found_name != std::string::npos && found_func != std::string::npos)
            {
                std::cout << "iam uint16" << std::endl;
                function_selector = 3;
                found_match = true;
                position_of_value = string.find(array_name_uint16_t[j], 0) + array_name_uint16_t[j].length() + 1;
                value = string.substr(position_of_value, string.length() - position_of_value);
                value_uint16_t = atoi(value.c_str());
                if (flag == true)
                {
                    output_string += "{\n\t[\n";
                }
                flag = false;
                break;
            }
            set_uint16_counter++;
        }

        for (int j = 0; j < sizeof(array_name_float) / sizeof(array_name_float[0]); j++)
        {
            std::size_t found_name = string.find(array_name_float[j], 0);
            std::size_t found_func = string.find(array_func[1], 0);

            if (found_name != std::string::npos && found_func != std::string::npos)
            {
                std::cout << "iam float" << std::endl;
                function_selector = 4;
                found_match = true;
                position_of_value = string.find(array_name_float[j], 0) + array_name_float[j].length() + 1;
                value = string.substr(position_of_value, string.length() - position_of_value);
                value_float = stof(value);
                if (flag == true)
                {
                    output_string += "{\n\t[\n";
                }
                flag = false;
                break;
            }
            set_float_counter++;
        }

        for (int j = 0; j < sizeof(array_name_bool) / sizeof(array_name_bool[0]); j++)
        {
            std::size_t found_name = string.find(array_name_bool[j], 0);
            std::size_t found_func = string.find(array_func[1], 0);
            if (found_name != std::string::npos && found_func != std::string::npos)
            {
                std::cout << "iam bool" << std::endl;
                function_selector = 5;
                found_match = true;
                if (string.find("enabled", 0) != std::string::npos)
                {
                    std::cout << "found enabled" << std::endl;
                    value_bool = true;
                }
                else if (string.find("1", 0) != std::string::npos)
                {
                    std::cout << "found 1" << std::endl;
                    value_bool = true;
                }

                if (flag == true)
                {
                    output_string += "{\n\t[\n";
                }
                flag = false;
                break;
            }
            set_bool_counter++;
        }
        switch (function_selector)
        {
        case 1:
            output_string += "\t\t";
            std::cout << "iam called counter get" << get_counter << std::endl;
            output_string += (can.*(can.funcs0[get_counter]))();
            break;
        case 2:
            output_string += "\t\t";
            std::cout << "iam called counter uint8" << set_uint8_counter << std::endl;
            output_string += (can.*(can.funcs1[set_uint8_counter]))(value_uint8_t);
            break;
        case 3:
            output_string += "\t\t";
            std::cout << "iam called counter uint16" << set_uint16_counter << std::endl;
            output_string += (can.*(can.funcs2[set_uint16_counter]))(value_uint16_t);
            break;
        case 4:
            output_string += "\t\t";
            std::cout << "iam called counter float" << set_float_counter << std::endl;
            output_string += (can.*(can.funcs3[set_float_counter]))(value_float);
            break;
        case 5:
            output_string += "\t\t";
            std::cout << "iam called counter bool" << set_bool_counter << std::endl;
            output_string += (can.*(can.funcs4[set_bool_counter]))(value_bool);
            value_bool = false;
            break;
        default:
            break;
        }

        output_string += ",";
        output_string += "\n";
    }
    if (found_match == false)
    {
        output_string += "\t\t";
        output_string += "Not yet implemented";
        output_string += "\n";
    }
    found_match = false;

    output_string += "\t]\n}";
    Fileioobj.writeLine("../../output.txt", output_string);

    return 0;
}
