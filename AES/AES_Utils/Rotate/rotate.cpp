#include "../AES_Utils.hpp"
void AES_Utils::rotate(vector<unsigned char>& target,const int& amount){
    vector<unsigned char> result(target.size());
    //FIXME: ADD AMOUNT TO THE ALGORITHM
    for (int i = 1; i <= target.size(); i++)
    {
        result[i%target.size()] = target[(i+1)%target.size()];
    }
    target=result;
}