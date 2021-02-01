#include "../KeyGeneration.hpp"
#include "../../AES_Utils/PrintingVectors/PrintingVector.hpp"
void KeyGeneration::rotate(vector<unsigned char>& target){
    vector<unsigned char> result(target.size());
    for (int i = 1; i <= target.size(); i++)
    {
        result[i%target.size()] = target[(i+1)%target.size()];
    }
    target=result;
}