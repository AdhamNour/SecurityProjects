#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include<cstdlib>

#include "AES/AES_Utils/VectorSlice/VectorSlice.hpp"
#include "AES/AES_Utils/SubBytes/SubBytes.hpp"

using namespace std;
int main(void)
{
    vector<unsigned char> vch (16);
    for (unsigned int i = 0; i <vch.size();i++)
        vch[i] = rand()%256;
    SubBytes(vch);

    for (auto &&i : vch)
        cout<<(int)i<<' ';

    cout<<endl;

    vector<unsigned char> vch2(4);
    sliceVector(vch,vch2,3);

    for (auto &&i : vch2)
        cout<<(int)i<<' ';
    return 0;
}