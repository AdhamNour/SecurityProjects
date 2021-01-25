#include "../../DES_Round.h"

#include "Expanstion_Permutation.h"

string DES_Round::expandRight(const string& target){
    string result(48,'0');
    for(int i = 0; i <48; i++){
        result[i]=target[expansion_permutation[i]];
    }
    return result;
}