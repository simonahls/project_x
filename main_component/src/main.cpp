#include <iostream>
#include "FileIO.h"
#include <can_messages/CAN_min_signals.h>

void function_write_output();
void function_read_input();
// first function to check 3 first str.
// secound check the secound word.
// third check the value.

// function pointers with a map.
//  std:map< std::string ,
int main(int argc, char *argv[])
{

    CAN_min_signals can;
    // std::cout << FileIO::readLine("input_file.txt") << std::endl;
    FileIO readline(void);

    // need to read from a file and execute the command with the help of fileio and can_messages.

    // write to a file with the

    return 0;
}
