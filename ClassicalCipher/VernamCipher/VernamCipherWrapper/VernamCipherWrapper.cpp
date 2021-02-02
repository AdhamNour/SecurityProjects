#include "VernamCipherWrapper.hpp"
#include "../VernamCipher.h"

string vernam_ciper(const string& plaintext,const string& key){
    static VernamCipher vc(key);
    return vc.encrypt(plaintext);
}