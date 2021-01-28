#ifndef DES_ALGORITHM
#define DES_ALGORITHM
#include <string>
#include "./KeyGeneration/KeyGeneration.h"
#include "../DataConverter/DataConverter.h"
#include "./DES_Functions/BlockEncryptor/BlockEncryptor.h"
using namespace std;
class DES
{
private:
    KeyGeneration keyGeneration;
    DataConverter dataConverter;
    BlockEncryptor blockEncryptor;
    void paddingPlainText(string &binarizedPlaintext);
public:
    string encrypt(const string &plaintext, const string &key);
    string decrypt(const string &ciphertext, const string &key);    
};


#endif