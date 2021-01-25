#include "../../DES_Round.h"

void DES_Round::xor_lists(string& target, const string&key){
    //TODO: need to transform target and keys into vector of boolean values
    for (int i = 0; i <target.length(); i++){
        bool targetbin =  target[i] == '1';
        bool keybin = key[i] == '1';
        bool result = targetbin^keybin;
        target[i] = result?'1':'0';
    }
}