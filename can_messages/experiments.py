import json
import os
import re

# ide to have a seperate file with all the info(lika a template easier to change) and the python script will look cleaner.
# i want to write to the c++ with varialbes from the json content.
# Then we need a funciton to transform the raw text to a string variable that we can write.
# And implement the variables to the text.

# variables to store the position of the data from Jsoninput file.
temperature_id = 0
humidity_id = 1

# variable to store the name of the jsoninputfile regardless of where it is located.
file_path = "min_signals.json"
FILE_NAME = os.path.basename(file_path[:-5])


# modify FILE_NAME to be the correct variable for CAN_min_signals
can_min_signals = "CAN_" + FILE_NAME[:-5]


# function to read and return the jason as dict.

def read_json_file_function(filename):
    json_dict = {}
    with open(filename) as json_fd:
        file_content_raw = json_fd.read(None)
        json_dict = json.loads(file_content_raw)

        return json_dict

# function to get value from json file
# if we spec 0 in the arg input_name then the name of the key will be returned


def function_to_get_value_from_json(input_name, key, position):
    data = read_json_file_function(file_path)[key]
    if input_name == 0:
        return key
    elif position == "value":
        return
    output_value = data[position][input_name]
    return output_value


"""     if key == "id":
        output_value = data
        return output_value
    else: """


# test funciton for function_to get...

print(function_to_get_value_from_json("length", "signals", humidity_id))
print(function_to_get_value_from_json("type", "signals", temperature_id))
print(function_to_get_value_from_json(0, "id", 0))


# I want to create the content for the source file for c++ component and return the string.

def read_source_string(filename):
    with open(filename) as source_fd:
        source_string = source_fd.read()

    return source_string


source_text_raw = read_source_string("input_source.txt")

# function to replace the values with the json keynames and values.


""" def insert_data_from_json_file():
    # we need all the variables?
    # do we want to assign it
    modified_file_content = original_file_content.replace(
        "text_to_be_replaced", replacement_text) """

"""    with open("new_file.txt", "w") as new_file:
       for x in range(4):
           y = 0
           for line in source_input:
                line = line.replace("sub_value_{}_{}".format(
                    y, x), replacement_array[z])
                new_file.write(line)
                y += 1
                z += 1
            x += 1
            z = 0 """


# Read the input file
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

# Write the modified input data to a new output file
with open("output_source.txt", "w") as output_file:
    output_file.write(input_data)


""" def function_to_replace_data_with_json_content():
    json_data = read_json_file_function(file_path)
    source_input = read_source_string("input_source.txt")
    replacement_array = ["temperature",
                         "float", 10, "the ambient temperature",
                         "humidity", "uint8_t", 7, "the ambient humidity percentage"]
    y = 0
    x = 0
    z = 0
    for x in range(4):
        for line in source_input:
            line = line.replace("sub_value_{}_{}".format(
                y, x), replacement_array[z])
        y += 1
        z += 1
    x += 1
    print(line) """

"""     replacment_array = "korv"
    y = 0
    x = 0
    for line in source_input:
        line = line.replace("sub_value_{}_{}, replacement_array".format(y, x)) """

# new_text = source_input.replace("sub_value_0_0", "korv")
# print(new_text)


def function_to_replace_data_from_tag_names():

    print("----------")
