#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

//#include "ClassicalCipher/CaeserCipher/CaeserCipher.h"
//#include "ClassicalCipher/PlayFairCipher/PlayFairCipher.h"
#include "ClassicalCipher/HillCipher/HillCipher.h"
using namespace std;
int main(void)
{
    try
    {
        HillCipher hillCipher({{5, 17},
                               {8, 3}});
        cout << hillCipher.encrypt("Adham  Nour") << endl;
    }
    catch (const char *msg)
    {
        cout << msg << endl;
    }
    return 0;
}