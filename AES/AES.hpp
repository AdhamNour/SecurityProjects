#ifndef AES_ALGORITHM
#define AES_ALGORITHM
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class AES
{
private:
    vector<unsigned char> mixColomns(const vector<unsigned char>& target);
    vector<unsigned char> InverseMixColomns(const vector<unsigned char>& target);
    vector<unsigned char> shiftRows(const vector<unsigned char>& target); 
    vector<unsigned char> InverseShiftRows(const vector<unsigned char>& target); 

public:
    string encrypt(const string& plaintext, const string& key);
    string decrypt(const string& ciphertext, const string& key);
};


#endif // AES_ALGORITHM