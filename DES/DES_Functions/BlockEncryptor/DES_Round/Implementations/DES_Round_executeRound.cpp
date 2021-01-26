#include "../DES_Round.h"

#include<iostream>

void DES_Round::executeRound(string& target, const string& key){
    //cout<<endl<<"[DES_Round::executeRound]:start"<<endl;
    //cout<<"The current target is\t"<<target<<endl;
    //cout<<"The Current key is\t"<<key<<endl;

    if(target.size() != 64){
        cerr << "There's a problem with executeRound, The length of the target is not 64" << endl;
        return;
    }
    string leftPart =target.substr(0,32);
    //cout<<"The left part of the target\t"<<leftPart<<endl;
    string rightPart =target.substr(32);
    //cout<<"The right part of the target\t"<<rightPart<<endl;
    string modifiedRightPart = expandRight(rightPart);
    //cout<<"The expanded right part of the target\t"<<modifiedRightPart<<endl;
    xor_lists(modifiedRightPart,key);
    //cout<<"The xored right part of the target\t"<<modifiedRightPart<<"\nwith the key\t\t\t"<<key<<endl;
    applySBox(modifiedRightPart);
    //cout<<"The right part of the target after applying SBox \t"<<modifiedRightPart<<endl;

    permuteRight(modifiedRightPart);
    //cout<<"The right part of the target after permute Right \t"<<modifiedRightPart<<endl;
    xor_lists(modifiedRightPart,leftPart);
    //cout<<"The xored right part of the target\t"<<modifiedRightPart<<"\nwith the leftPart\t"<<leftPart<<endl;
    target = rightPart + modifiedRightPart;
    //cout<<"The new Terget"<<target<<endl;
    //cout<<"[DES_Round::executeRound]:end"<<endl<<endl;

}
