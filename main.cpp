#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <cstdlib>

#include "AES/KeyGeneration/KeyGeneration.hpp"
#include "AES/AES_Utils/AES_Utils.hpp"
#include "AES/AES.hpp"
#include "DataConverter/DataConverter.h"

using namespace std;
int main(void)
{
    AES aes;
    cout<<aes.encrypt("0123456789ABCDEF0123456789ABCDEF","0123456789ABCDEF0123456789ABCDEF")<<endl;
    // vector<unsigned char> testingBlock ={ 124, 84, 153, 10, 196, 177, 24, 41, 167, 157, 163, 241, 99, 29, 101, 28};
    // auto resultBlock =aes.shiftRows(testingBlock);
    // AES_Utils::print(resultBlock,"resultBlock");
    return 0;
}