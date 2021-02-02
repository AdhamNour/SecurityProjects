#include"../AES_Utils.hpp"
#include "Inv_SBox/Inv_SBox.hpp"
void AES_Utils::InverseSubBytes(vector<unsigned char>& target){
    for (int i = 0; i < target.size(); i++)
    {
        target[i]=Inv_Sbox[target[i]];
    }
    
}