#include "BlockEncryptor.h"

string BlockEncryptor::finalPermutate(const string& target){
     string result(64,'0');
    for(int i = 0; i <64;i++){
        result[i]=target[inverse_permutation_table[i]];
    }
    return result;
}
