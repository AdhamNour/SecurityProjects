#include"SubBytes.hpp"
#include "../../AES_Constants/SBox/SBox.hpp"

void SubBytes(vector<unsigned char>& target){
    for (int i = 0; i < target.size(); i++)
    {
        target[i]=SBox[target[i]];
    }
    
}