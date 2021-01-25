#ifndef BLOCK_ENCRYPTOR
#define BLOCK_ENCRYPTOR
#include <vector>
#include <string>

#include "./DES_Round/DES_Round.h"

using namespace std;

class BlockEncryptor
{
private:
    DES_Round des_round;
    string initalPermutate(const string& target);
    string expandRight(const string& target);
public:
    string encryptBlock(const string& block, const vector<string>& keyList);
};


#endif