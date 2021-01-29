#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include<cstdlib>

#include "AES/AES_Utils/SubBytes/SubBytes.hpp"

using namespace std;
int main(void)
{
    vector<unsigned char> test(32);
    for (int i = 0; i < test.size(); i++)
    {
        test[i] = rand()%16;
        cout<<(int)test[i]<<' ';
    }
    cout<<endl;
    SubBytes(test);
    for (auto &&i : test)
    {
        cout<<(int)i<<' ';
    }
    cout<<endl;    
    return 0;
}