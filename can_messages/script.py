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

    replacement_array_values = []
    replacement_array_names = []

    # for loop to store the values from dict in a array.
    for signal in signals:
        replacement_array_values.extend(
            [signal['name'], signal['type'], str(signal['length']), signal['comment']])
        replacement_array_names.extend(["name", "type", "length", "comment"])

    with open("input_source.txt", "r") as input_file:
        input_data = input_file.read()

    for i, (value, name) in enumerate(zip(replacement_array_values, replacement_array_names)):
        input_data = re.sub(r"sub_value_" + str(i//4) +
                            "_" + str(i % 4), value, input_data)
        input_data = re.sub(r"sub_name_" + str(i//4) +
                            "_" + str(i % 4), name, input_data)

    # i want to replace all the file_name with min_signals
    input_data = input_data.replace("file_name", FILE_NAME)

    if not os.path.exists("output/src"):
        os.makedirs("output/src")

    with open("output/src/{}.cpp".format(FILE_NAME), "w") as output_file:
        output_file.write(input_data)
# function to write the source file.


def function_write_header_file():
    with open("input_header.txt", "r") as input_file:
        input_data = input_file.read()

    json_dict = import_json_file_function()
    signals = json_dict['signals']

    replacement_array_values = []
    replacement_array_names = []

    for signal in signals:
        replacement_array_values.extend(
            [signal['name'], signal['type'], str(signal['length']), signal['comment']])
        replacement_array_names.extend(["name", "type", "length", "comment"])

    with open("input_header.txt", "r") as input_file:
        input_data = input_file.read()

    for i, (value, name) in enumerate(zip(replacement_array_values, replacement_array_names)):
        input_data = re.sub(r"sub_value_" + str(i//4) +
                            "_" + str(i % 4), value, input_data)
        input_data = re.sub(r"sub_name_" + str(i//4) +
                            "_" + str(i % 4), name, input_data)

    # i want to replace all the file_name with min_signals
    input_data = input_data.replace("file_name", FILE_NAME)

    if not os.path.exists("output/include/can_messages"):
        os.makedirs("output/include/can_messages")
    with open("output/include/can_messages/{}.h".format(FILE_NAME), "w") as output_file:
        output_file.write(input_data)
# funciton to write the header file.


function_write_source_file()
function_write_header_file()
