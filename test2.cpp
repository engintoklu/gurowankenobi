#include <iostream>
#include <string>
#include "gurowan.hpp"

int main(int argc, char *argv[])
{
    //std::cout << gurowan_utils::quote_for_shell("a %b c") << std::endl;

    std::list<std::string> arguments;
    arguments.push_back("yanki");
    arguments.push_back("a");
    arguments.push_back("b c");
    arguments.push_back("%PATH%");
    arguments.push_back("\\\"");

    std::cout << gurowan_utils::join_into_command_line(arguments) << std::endl;

    system(gurowan_utils::join_into_command_line(arguments).c_str());

    return 0;
}
