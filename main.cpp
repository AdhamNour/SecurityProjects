#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>

#include "./DES/KeyGeneration/KeyGeneration.h"

using namespace std;
int main(void)
{
    KeyGeneration keyGeneration;
    auto x =keyGeneration.generateKeys("0000000000000000");
    for (auto &&i : x)
    {
        cout<<i<<endl;
    }
    
    return 0;
}