#include "../KeyGeneration.hpp"
#include "../../AES_Constants/SBox/SBox.hpp"
#include "../KeyGenerationConstants/RoundConstants.hpp"

#include "../../AES_Utils/SubBytes/SubBytes.hpp"
#include "../../AES_Utils/VectorSlice/VectorSlice.hpp"

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
        vector<unsigned char> currentKey,PreviousKey(keys[i]),row0(4),rcon ={(unsigned char)RoundConstants[i],0,0,0};
        sliceVector(PreviousKey,row0,12);
        rotate(row0);//rotate the key
        SubBytes(row0);
    }
    
}