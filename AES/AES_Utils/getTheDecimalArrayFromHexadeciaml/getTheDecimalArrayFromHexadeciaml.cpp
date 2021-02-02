#include "../AES_Utils.hpp"

vector<unsigned char> AES_Utils::getTheDecimalArrayFromHexadeciaml(const string& key){
    vector<unsigned char> result(key.length()/2);
    for (int i = 0; i < key.length(); i+=2)
    {
        result[i/2]=dataConverter.convertFromHexadecimal2Decimal(key.substr(i,2));
    }
    return result;
}