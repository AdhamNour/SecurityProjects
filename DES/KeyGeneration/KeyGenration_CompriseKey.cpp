#include "KeyGeneration.h"
#include "./KeyGenerationConstants/Permutation_Choice_One.h"
void KeyGeneration::compriseKey(const string &key_bin,string &C,string &D){
    for (int i = 0; i < 28; i++)
    {
        C[i]=key_bin[permutedChoice1[i-1]];
        D[i]=key_bin[permutedChoice1[16+i-1]];
    }
}