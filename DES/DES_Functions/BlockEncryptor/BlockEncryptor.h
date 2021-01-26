#ifndef BLOCK_ENCRYPTOR
#define BLOCK_ENCRYPTOR
#include <vector>
#include <string>
#include <iostream>

#include "./DES_Round/DES_Round.h"
#include "InitialPermutation.h"

using namespace std;


class BlockEncryptor
{
private:
    DES_Round des_round;
    int inverse_permutation_table[64];
    string initalPermutate(const string& target);
    string finalPermutate(const string& target);

    string expandRight(const string& target);
public:
    string encryptBlock(const string& block, const vector<string>& keyList);
    BlockEncryptor();
    // void printPermutationTables();
};


#endif