#include "VigenereCipher.h"
#include "../CaeserCipher/CaeserCipher.h"
#include<ctype.h>
string vigenereCihper(const string& plaintext,const string& key, const bool& auto_mode){
    string ciphertext;
    string Key = key + (auto_mode?plaintext:"");
    for (int i = 0; i < plaintext.length(); i++)
    {
        char keychar = tolower(Key[i%Key.length()]);
        ciphertext += caeserCipher(plaintext.substr(i,1),(int)(keychar-'a'));
    }
    
    
    return ciphertext;
}