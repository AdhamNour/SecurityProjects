#include "../../DES_Round.h"
#include "Permutation_Table.h"

#include <iostream>
void DES_Round::permuteRight(string& target){
    if(target.length() != 32){
        cerr<<"There's error occured in \"permuteRight\" the target length is not 32"<<endl;
        return;
    }
    string result(target);
    for (int i = 0; i < result.length(); i++)
    {
        result[i] =target[permutationTable[i]-1];
    }
    
}
