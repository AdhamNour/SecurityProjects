#include "BlockEncryptor.h"
string BlockEncryptor::encryptBlock(const string& block, const vector<string>& keyList){
    string initialPermutatedBlock = initalPermutate(block);
    for (int i = 0; i < keyList.size(); i++)
    {
        des_round.executeRound(initialPermutatedBlock,keyList[i]);
    }
    string final_block = initialPermutatedBlock.substr(32)+initialPermutatedBlock.substr(0,32);
    string result = finalPermutate(final_block);

    return result;
}