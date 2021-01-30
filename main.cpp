#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>

#include "AES/KeyGeneration/KeyGeneration.hpp"

using namespace std;
int main(void)
{
    string str = "0123456789ABCDEF0123456789ABCDEF";
    KeyGeneration keyGeneration;
    vector<vector<unsigned char>> z = keyGeneration.genrtateKeys(str);
    for (auto &&i : z)
    {
        cout<<i.size() <<endl;
        cout << '[';
        for (auto &&j : i)
        {
            cout <<' '<<(int) j << ',';
        }
        cout << ']' << endl;
    }

    return 0;
}