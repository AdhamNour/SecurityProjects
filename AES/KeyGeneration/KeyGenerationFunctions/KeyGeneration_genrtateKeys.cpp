#include "../KeyGeneration.hpp"
#include "../../AES_Constants/SBox/SBox.hpp"
#include "../KeyGenerationConstants/RoundConstants.hpp"
#include "../../AES_Utils/SubBytes/SubBytes.hpp"
#include <iostream>
vector<vector<unsigned char> > KeyGeneration::genrtateKeys(const string&key){
    if(key.length() != 32 ){
        cerr<<"The key is not 128 bit, sadly this algorithm is designed only to work on 128 bit"<<endl;
        return {}; //return an empty vector as asign to generation failer
    }
    vector<unsigned char> AES_Key = getTheDecimalArrayFromHexadeciaml(key);
    vector<vector<unsigned char> > keys (10);
    keys[0]=AES_Key;
    for (int i = 0; i < keys.size(); i++)
    {
        vector<unsigned char> currentKey,PreviousKey(keys[i]),row0(4);
        for (int i = 13; i < PreviousKey.size(); i++)
        {
            row0[i-13]=PreviousKey[i];
        }
        row0[3]=PreviousKey[12];
        SubBytes(row0);
    }
    
}