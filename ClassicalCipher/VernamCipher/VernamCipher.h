#ifndef VERNAM_CIPHER
#define VERNAM_CIPHER
#include <string>
#include <vector>

#include "../HillCipher/HillCipher.h"
using namespace std;
class VernamCipher
{
private:
    string currentKey = "";
    vector<vector<char>> keyMatrix = {
        {1, 2, 3},
        {1, 2, 3},
        {1, 2, 3}
    };
    HillCipher cipher = HillCipher(keyMatrix);

    void generateKeyMatrix();

public:
    VernamCipher(const string &key) { setKey(key); };
    void setKey(const string &key);
    string encrypt(const string& plaintext);
};
#endif