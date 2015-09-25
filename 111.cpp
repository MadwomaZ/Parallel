#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int main()
{
    std::string x;
    x.resize(0);
    x[0] = 'T';
    cout << x << x[0] << std::endl;
    return 0;
}


