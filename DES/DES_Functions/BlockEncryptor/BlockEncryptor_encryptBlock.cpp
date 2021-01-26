#include "BlockEncryptor.h"
#include "../../DataConverter/DataConverter.h"
string BlockEncryptor::encryptBlock(const string& block, const vector<string>& keyList){
    //cout<<endl<<"[BlockEncryptor::encryptBlock]: start"<<endl;
    string initialPermutatedBlock = initalPermutate(block);
    for (int i = 0; i < keyList.size(); i++)
    {   
        //cout<<"it is the round number "<<i<<endl;
        //cout<<"the previous initialPermutatedBlock \t"<<initialPermutatedBlock<<endl;
        //cout<<"the current Key \t"<<keyList[i]<<endl;
        des_round.executeRound(initialPermutatedBlock,keyList[i]);        
        //cout<<"the current initialPermutatedBlock \t"<<initialPermutatedBlock<<endl<<endl;
    }
    string final_block = initialPermutatedBlock.substr(32)+initialPermutatedBlock.substr(0,32);
    //cout<<"finalblock\t"<<final_block<<endl;
    string result = finalPermutate(final_block);
    //cout<<"[BlockEncryptor::encryptBlock]: end"<<endl;
    return result;
}