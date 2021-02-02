#include "../AES_Utils.hpp"
void AES_Utils::rotate(vector<unsigned char> &target, const int &amount,const bool& toRight)
{
    vector<unsigned char> result(target.size());
    //FIXME:Need some optimization
    for (size_t x = 0; x < amount; x++)
    {
        for (int i = 1; i <= target.size(); i++)
        {
            if(toRight){
                result[(i + 1) % target.size()] = target[i % target.size()];
            }
            else
            {
                result[i % target.size()] = target[(i + 1) % target.size()];
            }
        }
        target = result;
    }
}