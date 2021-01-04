#include <iostream>
#include "ClassicalCipher/CaeserCipher/CaeserCipher.h"
using namespace std;
int main(void){
    string x =  caeserCipher("const string &plaintext", 10);
    cout<<x<<endl;
    return 0;
}