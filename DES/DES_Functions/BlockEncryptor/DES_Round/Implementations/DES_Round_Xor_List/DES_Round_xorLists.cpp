#include "../../DES_Round.h"
#include <iostream>
void DES_Round::xor_lists(string& target1, const string&target2){
    //TODO: need to transform target and keys into vector of boolean values
    if(target1.size() != target2.size()){
        cerr<<"There's an error in DES_Round::xor_lists, The target and the key are not the same "<<endl;
        return;
    }
    for (int i = 0; i <target1.length(); i++){
        bool target1bin =  target1[i] == '1';
        bool target2bin = target2[i] == '1';
        bool result = target1bin^target2bin;
        target1[i] = result?'1':'0';
    }
}