import pytest


inputfile_content = """
set temperature 50
"""

expected_read_content = """
set temperature 50
"""


def test_mc():
    input_filename = "input.txt"
    output_filename = "input.txt"  # So far is input later: output.
    print(inputfile_content)

    with open(input_filename, "w") as fd:
        fd.write(inputfile_content)

    read_output = ""
    with open(output_filename) as fd:
        read_output = fd.read()
