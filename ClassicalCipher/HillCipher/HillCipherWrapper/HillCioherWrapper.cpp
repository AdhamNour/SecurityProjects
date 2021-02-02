#include "HillCipherWrapper.hpp"

string hill_cipher(const string&plaintext,const vector<vector<char> >& key){
    static  HillCipher hill(key);
    return hill.encrypt(plaintext);
}