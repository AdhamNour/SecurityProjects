#ifndef AES_ALGORITHM
#define AES_ALGORITHM
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class AES
{
private:
    
public:
    vector<unsigned char> shiftRows(const vector<unsigned char>& target);
    vector<unsigned char> mixColomns(const vector<unsigned char>& target);
    string encrypt(const string& plaintext, const string& key);
};


#endif // AES_ALGORITHM