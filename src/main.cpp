#include <iostream>
#include <cstring>
#include "input.h"
#include "global.h"

using namespace std;
int ibase = 10, obase = 10, scale = 0;

int main(int argc, char** argv)
{
    if(version(argc, argv)) return 0;//to check the version informantion, directly exit after output
    

    string s;

    while(getline(cin, s))
    {
        input(s);
    }

    
    
    return 0;
}