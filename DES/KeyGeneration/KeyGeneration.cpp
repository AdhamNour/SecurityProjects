#include "KeyGeneration.h"
#include "./KeyGenerationConstants/LeftCircularShift.h"
#include "./KeyGenerationConstants/Permutation_Choice_Two.h"
#include "../DataConverter/DataConverter.h"
#include <iostream>
vector<string> KeyGeneration::generateKeys(const string &key)
{
    string key_bin;
    DataConverter dataConverter;
    dataConverter.Binarize(key , key_bin);
    string C(28,'0');
    string D(28,'0');
    compriseKey(key_bin, C,D);
    vector<string> keys(16);
    for (int i = 0; i < keys.size(); i++)
    {
        left_shift(C,LeftCircularShift[i]);
        left_shift(D,LeftCircularShift[i]);
        string CD = C+D;
        string final_key(24*2,'0');
        for (int i = 0; i < final_key.length(); i++)
        {
            final_key[i] = CD[permutedChoice2[i]-1];
        }
        keys[i]=final_key;
    }
    return keys;
}