#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>

#include "ClassicalCipher/VernamCipher/VernamCipher.h"

using namespace std;
int main(void)
{
    VernamCipher cipher("Spartan");
    cout<< cipher.encrypt("PXPTYRFJ")<<endl
    <<cipher.encrypt("FXGWYEAU")<<endl
    <<cipher.encrypt("BBMHCXHP")<<endl;

    return 0;
}