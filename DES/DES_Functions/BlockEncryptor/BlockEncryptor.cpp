#include "BlockEncryptor.h"
string BlockEncryptor::encryptBlock(const string& block, const vector<string>& keyList){
    string initialPermutatedBlock = initalPermutate(block);
    for (int i = 0; i < keyList.size(); i++)
    {
        des_round.executeRound(initialPermutatedBlock,keyList[i]);
    }
    
    return "1111";
}