#include "../DES_Round.h"

#include<iostream>

void DES_Round::executeRound(string& target, const string& key){
    if(target.size() != 64){
        cerr << "There's a problem with executeRound, The length of the target is not 64" << endl;
        return;
    }
    string leftPart =target.substr(0,32);
    string rightPart =target.substr(32);
    string modifiedRightPart = expandRight(rightPart);
    xor_lists(modifiedRightPart,key);
    applySBox(modifiedRightPart);
    permuteRight(modifiedRightPart);
    xor_lists(modifiedRightPart,leftPart);
    target = rightPart + modifiedRightPart;
}
