#include <iostream>
#include <cstring>

void version_message()
{
    std::cout << "This is a calculator\n";//There should be more
}

bool version(int argc, char** argv)
{
    if(argc == 1) return false;
    for (int i = 1; i < argc; i++)
    {
        if(argv[i][0] == '-' && strchr(argv[i], 'v'))
        {
            version_message();
            return true;
        }
    }
    std::cout << "syntax error\n";
    return true;
}