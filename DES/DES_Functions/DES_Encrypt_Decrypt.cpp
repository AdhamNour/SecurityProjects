#include<vector>
#include<algorithm>

#include "../DES.h"

string DES::encrypt(const string &plaintext, const string &key){
    vector<string> keys = keyGeneration.generateKeys(key);    
    string binarizedPlainText ;
    dataConverter.Binarize(plaintext,binarizedPlainText);
    paddingPlainText(binarizedPlainText);
    string encryptedBinary ;
    for (int i = 0; i < binarizedPlainText.size(); i+=64)
    {   
        encryptedBinary += blockEncryptor.encryptBlock(binarizedPlainText.substr(i,64), keys);
    }

    return dataConverter.Hexadecimalize(encryptedBinary);
}

string DES::decrypt(const string &ciphertext, const string &key){
    vector<string> keys = keyGeneration.generateKeys(key);
    reverse(keys.begin(),keys.end());
    string binarizedPlainText ;
    dataConverter.Binarize(ciphertext,binarizedPlainText);
    paddingPlainText(binarizedPlainText);
    string encryptedBinary ;
    for (int i = 0; i < binarizedPlainText.size(); i+=64)
    {
        encryptedBinary += blockEncryptor.encryptBlock(binarizedPlainText.substr(i,64), keys);
    }
    
    return dataConverter.Hexadecimalize(encryptedBinary);
}