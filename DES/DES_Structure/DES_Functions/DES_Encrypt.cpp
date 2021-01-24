#include "../../DES.h"
#include<vector>

string DES::encrypt(const string &plaintext, const string &key){
    vector<string> keys = keyGeneration.generateKeys(key);
    string binarizedPlainText ;
    dataConverter.Binarize(plaintext,binarizedPlainText);
    paddingPlainText(binarizedPlainText);

    return dataConverter.Hexadecimalize(binarizedPlainText)+"\nnot finished yet\n";
}