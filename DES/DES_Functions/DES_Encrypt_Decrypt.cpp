#include<vector>
#include<algorithm>

#include "../DES.h"

string DES::encrypt(const string &plaintext, const string &key){
    //cout<<"[DES::encrypt]: start"<<endl;
    vector<string> keys = keyGeneration.generateKeys(key);
    for (int i = 0; i < keys.size(); i++)
    {
        //cout<<"The key number "<<i<<'\t'<<keys[i]<<endl;
    }
    
    string binarizedPlainText ;
    dataConverter.Binarize(plaintext,binarizedPlainText);
    //cout<<"binarizedPlainText\t"<<binarizedPlainText<<endl;
    paddingPlainText(binarizedPlainText);
    //cout<<"padded binarizedPlainText\t"<<binarizedPlainText<<endl;
    string encryptedBinary ;
    for (int i = 0; i < binarizedPlainText.size(); i+=64)
    {   //cout<<"encryptedBinary before execute encrypt block :\t"<<encryptedBinary<<endl;
        encryptedBinary += blockEncryptor.encryptBlock(binarizedPlainText.substr(i,64), keys);
        //cout<<"encryptedBinary before execute encrypt block :\t"<<encryptedBinary<<endl;
    }
    //cout<<"[DES::encrypt]: end"<<endl;

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