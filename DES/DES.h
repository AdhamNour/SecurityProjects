#ifndef DES_ALGORITHM
#define DES_ALGORITHM
#include <string>
#include "./KeyGeneration/KeyGeneration.h"
#include "./DataConverter/DataConverter.h"
using namespace std;
class DES
{
private:
    KeyGeneration keyGeneration;
    DataConverter dataConverter;
    void paddingPlainText(string &binarizedPlaintext);
public:
    string encrypt(const string &plaintext, const string &key);
};


#endif