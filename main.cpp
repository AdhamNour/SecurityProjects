#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>

//#include "ClassicalCipher/CaeserCipher/CaeserCipher.h"
//#include "ClassicalCipher/PlayFairCipher/PlayFairCipher.h"
#include "ClassicalCipher/VigenereCipher/VigenereCipher.h"
using namespace std;
int main(void)
{
    string str ="adham adham adham adham adham";
    cout << vigenereCihper(str,"hell")<<endl;
    return 0;
}