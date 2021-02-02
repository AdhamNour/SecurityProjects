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
    auto res = aes.encrypt("0123456789ABCDEF0123456789ABCDEF","0123456789ABCDEF0123456789ABCDEF");
    cout<<res<<endl;
    cout<<aes.decrypt(res,"0123456789ABCDEF0123456789ABCDEF")<<endl;
    return 0;
}