#include "BlockEncryptor.h"
#include "../../DES_Constants/Initial_Permutation.h"
string BlockEncryptor::initalPermutate(const string& target){
    string result(64,'0');
    for(int i = 0; i <64;i++){
        result[i]=target[InitialPermutation[i]];
    }
    return result;
}