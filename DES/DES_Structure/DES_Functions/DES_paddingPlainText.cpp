#include "../../DES.h"

void DES::paddingPlainText(string&binarizedPlaintext){
    int remaining_zeros = 64-(binarizedPlaintext.length()%64); //finding the rest zeros that should be added to plaintext to be multiple of 64
    if(remaining_zeros != 64)
    {
        string pad = string(remaining_zeros,'0'); //pad string
        binarizedPlaintext = pad + binarizedPlaintext;
    }
}