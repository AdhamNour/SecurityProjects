#include"../AES_Utils.hpp"
#include "SBox/SBox.hpp"
void AES_Utils::SubBytes(vector<unsigned char>& target){
    for (int i = 0; i < target.size(); i++)
    {
        target[i]=SBox[target[i]];
    }
    
}