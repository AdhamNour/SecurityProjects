#include "../KeyGeneration.hpp"
void KeyGeneration::rotate(vector<unsigned char>& target){
    for (int i = 1; i <= target.size(); i++)
    {
        target[i%target.size()] = target[(i+1)%target.size()];
    }
}