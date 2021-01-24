#include "HillCipher.h"
#include <iostream>
void HillCipher::setKey(const vector<vector<char> >& key){
    if(!checkSquare(key)){
        throw "not square key";
    }
    if(this->key != key){
        this->key = key;
    }
}

void HillCipher::padTheString(string& str){
    while (str.length()%key.size()!=0)
    {
        str+="x";
    }    
}

string HillCipher::encrypt(const string & plainText){
    string plaintext(plainText);
    padTheString(plaintext);
    string ciphertext;
    for (int i = 0; i < plaintext.length(); i+=key.size())
    {
        ciphertext+= multiply(this->key,plaintext.substr(i,key.size()));
    }
    return ciphertext;
    
}