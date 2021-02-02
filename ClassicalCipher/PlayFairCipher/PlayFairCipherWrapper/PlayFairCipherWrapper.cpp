#include "PlayFairCipherWrapper.hpp"
#include "../PlayFairCipher.h"

string playfair(const string& plaintext,const string&key){
    static PlayFairCipher pfc(key);
    return(pfc.encrypte(plaintext));
}