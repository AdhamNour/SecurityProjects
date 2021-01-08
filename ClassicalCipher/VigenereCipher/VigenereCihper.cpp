#include "VigenereCipher.h"
#include "../CaeserCipher/CaeserCipher.h"
string vigenereCihper(const string& plaintext,const string& key){
    string ciphertext;
    for (int i = 0; i < plaintext.length(); i++)
    {
        char keychar = tolower(key[i%key.length()]);
        ciphertext += caeserCipher(plaintext.substr(i,1),(int)(keychar-'a'));
    }
    return ciphertext;
}