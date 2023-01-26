import json
import os
import re


# variable to store the name of the jsoninputfile regardless of where it is located.
file_path = "min_signals.json"
FILE_NAME = os.path.basename(file_path[:-5])


def function_write_source_file():
    with open("input_source.txt", "r") as input_file:
        input_data = input_file.read()

    replacement_array_values = ["temperature", "float", "10", "the ambient temperature",
                                "humidity", "uint8_t", "7", "the ambient humidity percentage"]
    replacement_array_names = ["name", "type", "length",
                               "comment", "name", "type", "length", "comment"]

    for i, (value, name) in enumerate(zip(replacement_array_values, replacement_array_names)):
        input_data = re.sub(r"sub_value_" + str(i//4) + "_" +
                            str(i % 4), value, input_data)
        input_data = re.sub(r"sub_name_" + str(i//4) + "_" +
                            str(i % 4), name, input_data)

    # i want to replace all the file_name with min_signals
    input_data = input_data.replace("file_name", FILE_NAME)

    with open("output_source.txt", "w") as output_file:
        output_file.write(input_data)


def function_write_header_file():
    with open("input_header.txt", "r") as input_file:
        input_data = input_file.read()

    replacement_array_values = ["temperature", "float", "10", "the ambient temperature",
                                "humidity", "uint8_t", "7", "the ambient humidity percentage"]
    replacement_array_names = ["name", "type", "length",
                               "comment", "name", "type", "length", "comment"]

    for i, (value, name) in enumerate(zip(replacement_array_values, replacement_array_names)):
        input_data = re.sub(r"sub_value_" + str(i//4) + "_" +
                            str(i % 4), value, input_data)
        input_data = re.sub(r"sub_name_" + str(i//4) + "_" +
                            str(i % 4), name, input_data)
    input_data = input_data.replace("file_name", FILE_NAME)
    input_data = input_data.replace("FILE_NAME", FILE_NAME.upper())
    with open("output_header.txt", "w") as output_file:
        output_file.write(input_data)


function_write_source_file()
function_write_header_file()
