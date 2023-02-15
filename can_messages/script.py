import json
import os

# variable to store the name and path to the json input inputfile.
file_path = "signals_biglist.json"
FILE_NAME = os.path.basename(file_path[:-5])


def import_json_file_function(file_path_arg):
    json_dict = {}
    with open(file_path_arg) as json_fd:
        file_content_raw = json_fd.read(None)
        json_dict = json.loads(file_content_raw)

        return json_dict
# function to import data from json file. specified in var file_path


def signals_in_json():
    generate_input = import_json_file_function(file_path)
    generate_signals = generate_input['signals']
    i = 0
    for i, signal in enumerate(generate_signals):
        i += 1
    return i


def generate_functions_from_template():
    with open("input/template_set_and_get_function.txt", "r") as input_file:
        input_data = input_file.read()
        input_file.close()
        input_mod_data = ""
        output_data = ""

        for i in range(signals_in_json()):
            # need to change the input data to reflect to 0_0 to 11_0 or something
            input_mod_data = input_data.replace(
                "sub_value_0", "sub_value_{}".format(i))
            input_mod_data = input_mod_data.replace(
                "sub_name_0", "sub_name_{}".format(i))
            input_mod_data += "\n"
            output_data += input_mod_data

    return output_data

    # for i, signal in enumerate(generate_signals):
    #     for j, (key, value) in enumerate(signal.items()):
    #         # place for how many signals in generate_Signals functions to replace.

    #         input_data = input_data.replace("sub_value_" + str(i) +
    #                                         "_" + str(j), str(value))
    #         input_data = input_data.replace("sub_name_" + str(i) +
    #                                         "_" + str(j), key)

    # open template and write for how many key value pairs in signals.

    # from template input txt generate functions from signal name and value.
    # we get how many signals in i
    # we can get the name (key) and the value from value.

    # input_data = input_data.replace("sub_value_" + str(i) +
    #                             "_" + str(j), str(value))
    # input_data = input_data.replace("sub_name_" + str(i) +
    #                             "_" + str(j), key)

    # i want to generate the input source dependent on how many signals there are in the signals json.


def generate_comment_header_file():
    try:
        with open("input/comments_header.txt", "r") as input_file:
            input_data = input_file.read()
            input_mod_data = ""
            output_data = ""
            for i in range(signals_in_json()):
                # need to change the input data to reflect to 0_0 to 11_0 or something
                input_mod_data = input_data.replace(
                    "sub_value_0", "sub_value_{}".format(i))
                input_mod_data += "\n"
                output_data += input_mod_data
    except FileNotFoundError:
        print("File not found")
        return ""
    except IOError:
        print("Error reading file")
        return ""

    return output_data


def generate_id_source_function():
    with open("input/template_id.txt", "r") as input_file:
        input_data = input_file.read()
    input_file.close
    input_mod_data = ""
    output_data = ""
    number = 0
    for i in range(signals_in_json()):
        # need to change the input data to reflect to 0_0 to 11_0 or something
        number += 2
        input_mod_data = input_data.replace(
            "sub_value_0", "sub_value_{}".format(i))
        input_mod_data = input_mod_data.replace(
            "sub_name_0", "sub_name_{}".format(i))
        input_mod_data = input_mod_data.replace(
            "id_value", "{}".format(number))
        output_data += input_mod_data
        output_data += "\n"

    return output_data


def generate_id_header():
    with open("input/header_id.txt", "r") as input_file:
        input_data = input_file.read()
    input_file.close
    input_mod_data = ""
    output_data = ""
    for i in range(signals_in_json()):
        # need to change the input data to reflect to 0_0 to 11_0 or something
        input_mod_data = input_data.replace(
            "sub_value_0", "sub_value_{}".format(i))
        input_mod_data = input_mod_data.replace(
            "sub_name_0", "sub_name_{}".format(i))
        output_data += input_mod_data
        output_data += "\n"

    return output_data


def read_top_code_source_file():
    with open("input/top_code_source.txt", "r") as input_file:
        input_data = input_file.read()
    return input_data


def read_top_code_header_file():
    with open("input/top_code_header.txt", "r") as input_file:
        input_data = input_file.read()
    return input_data


def function_write_source_file():
    source_file = read_top_code_source_file()
    source_file += generate_id_source_function()
    source_file += "}\n"
    source_file += generate_functions_from_template()

    json_dict = import_json_file_function(file_path)
    signals = json_dict['signals']

    for i, signal in enumerate(signals):
        for j, (key, value) in enumerate(signal.items()):
            source_file = source_file.replace("sub_value_" + str(i) +
                                              "_" + str(j), str(value))
            source_file = source_file.replace("sub_name_" + str(i) +
                                              "_" + str(j), key)
    # i want to replace all the file_name with min_signals
    source_file = source_file.replace("file_name", FILE_NAME)
    source_file = source_file.replace("FILE_NAME", FILE_NAME)

    # i want to replace the id value with main_key_value_0
    source_file = source_file.replace("main_key_value_0", json_dict["id"])

    if not os.path.exists("output/src"):
        os.makedirs("output/src")

    with open("output/src/CAN_{}.cpp".format(FILE_NAME), "w") as output_file:
        output_file.write(source_file)
# function to write the source file.


def function_write_header_file():
    header_file = read_top_code_header_file()
    header_file += generate_comment_header_file()
    header_file += "private:\n"
    header_file += "\tuint8_t m_startMsgId;\n"
    header_file += generate_id_header()
    header_file += "};\n#endif //HEADER_FILE_NAME_H"

    json_dict = import_json_file_function(file_path)
    signals = json_dict['signals']

    for i, signal in enumerate(signals):
        for j, (key, value) in enumerate(signal.items()):
            header_file = header_file.replace("sub_value_" + str(i) +
                                              "_" + str(j), str(value))
            header_file = header_file.replace("sub_name_" + str(i) +
                                              "_" + str(j), key)

    # i want to replace all the file_name with min_signals
    header_file = header_file.replace("file_name", FILE_NAME)
    header_file = header_file.replace("FILE_NAMN", FILE_NAME.upper())

    if not os.path.exists("output/include/can_messages"):
        os.makedirs("output/include/can_messages")
    with open("output/include/can_messages/CAN_{}.h".format(FILE_NAME), "w") as output_file:
        output_file.write(header_file)
# funciton to write the header file.


function_write_source_file()
function_write_header_file()
