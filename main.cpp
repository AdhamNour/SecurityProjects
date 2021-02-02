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

using namespace std;
int main(void)
{
    auto x = AES_Utils::getTheDecimalArrayFromHexadeciaml("0123456789ABCDEF1536247890ABCDEF");
    AES aes;
    auto y = aes.mixColomns(x);
    AES_Utils::print(y,"y");    
    return 0;
}