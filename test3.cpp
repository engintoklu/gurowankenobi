#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "gurowan.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    std::FILE *f = gurowan_utils::pipe_open("dir");
    while (true)
    {
        char line[256];
        if (std::fgets(line, 256, f))
        {
            std::cout << line << std::endl;
        }
        else
        {
            break;
        }
    }
    gurowan_utils::pipe_close(f);
    return 0;
}
