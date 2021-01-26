#include "../../DES_Round.h"

#include "Expanstion_Permutation.h"
#include <iostream>

string DES_Round::expandRight(const string& target){
    // The output is in the correct format
    string result(48,'0');
    for(int i = 0; i <48; i++){
        result[i]=target[expansion_permutation[i]-1];
        if(result[i] != '0' && result[i] != '1')
            cerr<<"error at \t"<<i<<endl;
    }
    return result;
}