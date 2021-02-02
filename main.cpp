#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>

#include "AES/KeyGeneration/KeyGeneration.hpp"
#include "AES/AES_Utils/AES_Utils.hpp"

using namespace std;
int main(void)
{
    KeyGeneration keyGeneration;
    auto x = keyGeneration.genrtateKeys("0123456789ABCDEF0123456789ABCDEF");
    for (auto &&i : x)
    {
        AES_Utils::print(i,"");
    }
    vector<unsigned char> currRow;
    AES_Utils::sliceVector(x[10],currRow,0,4);
    AES_Utils::print(currRow,"test Result");
    
    return 0;
}