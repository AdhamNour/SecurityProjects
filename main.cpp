#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>

#include "AES/KeyGeneration/KeyGeneration.hpp"

using namespace std;
int main(void)
{
    string x(32,'A');
    KeyGeneration keyGen;
    vector<unsigned char> res = keyGen.getTheDecimalArrayFromHexadeciaml(x);
    for (auto &&i : res)
    {
        cout<<(int) i <<' ';
    }
    cout<<endl<<res.size()<<endl;
    return 0;
}