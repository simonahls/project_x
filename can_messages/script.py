import json
import os
import re

# variable to store the name and path to the json input inputfile.
file_path = "min_signals.json"
FILE_NAME = os.path.basename(file_path[:-5])


def import_json_file_function():
    json_dict = {}
    with open(file_path) as json_fd:
        file_content_raw = json_fd.read(None)
        json_dict = json.loads(file_content_raw)

        return json_dict
# function to import data from json file. specified in var file_path


def function_write_source_file():
    with open("input_source.txt", "r") as input_file:
        input_data = input_file.read()

    json_dict = import_json_file_function()
    signals = json_dict['signals']

    with open("input_source.txt", "r") as input_file:
        input_data = input_file.read()

    for i, signal in enumerate(signals):
        for j, (key, value) in enumerate(signal.items()):
            input_data = input_data.replace("sub_value_" + str(i) +
                                            "_" + str(j), str(value))
            input_data = input_data.replace("sub_name_" + str(i) +
                                            "_" + str(j), key)
    # i want to replace all the file_name with min_signals
    input_data = input_data.replace("file_name", FILE_NAME)

    # i want to replace the id value with main_key_value_0
    input_data = input_data.replace("main_key_value_0", json_dict["id"])

    if not os.path.exists("output/src"):
        os.makedirs("output/src")

    with open("output/src/CAN_{}.cpp".format(FILE_NAME), "w") as output_file:
        output_file.write(input_data)
# function to write the source file.


def function_write_header_file():
    with open("input_header.txt", "r") as input_file:
        input_data = input_file.read()

    json_dict = import_json_file_function()
    signals = json_dict['signals']

    with open("input_header.txt", "r") as input_file:
        input_data = input_file.read()

    for i, signal in enumerate(signals):
        for j, (key, value) in enumerate(signal.items()):
            input_data = input_data.replace("sub_value_" + str(i) +
                                            "_" + str(j), str(value))
            input_data = input_data.replace("sub_name_" + str(i) +
                                            "_" + str(j), key)

    # i want to replace all the file_name with min_signals
    input_data = input_data.replace("file_name", FILE_NAME)

    if not os.path.exists("output/include/can_messages"):
        os.makedirs("output/include/can_messages")
    with open("output/include/can_messages/CAN_{}.h".format(FILE_NAME), "w") as output_file:
        output_file.write(input_data)
# funciton to write the header file.


function_write_source_file()
function_write_header_file()
