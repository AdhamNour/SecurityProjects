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
    auto x =keyGeneration.generateKeys("ABCDEDCBA5432ACB");
    for (auto &&i : x)
    {
        cout<<i<<endl;
    }
    
    return 0;
}