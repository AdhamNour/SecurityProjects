#include "VernamCipher.h"
#include <stdlib.h>
void VernamCipher::setKey(const string &key)
{
    if (this->currentKey != key)
    {
        this->currentKey = key;
        unsigned int sum = 0;
        for (int i = 0; i < key.length(); i++)
        {
            sum += (int)key[i];
        }
        srand(sum);
    }
}

void VernamCipher::generateKeyMatrix()
{
    for (int i = 0; i < this->keyMatrix.size(); i++)
    {
        for (int j = 0; j < this->keyMatrix[i].size(); j++)
        {
            this->keyMatrix[i][j] = rand() % 26;
        }
    }
    cipher.setKey(this->keyMatrix);
}

string VernamCipher::encrypt(const string &plaintext){
    generateKeyMatrix();
    return cipher.encrypt( plaintext);
}