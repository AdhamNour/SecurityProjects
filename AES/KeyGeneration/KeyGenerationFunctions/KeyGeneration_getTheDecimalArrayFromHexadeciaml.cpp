#include "../KeyGeneration.hpp"

vector<unsigned char> KeyGeneration::getTheDecimalArrayFromHexadeciaml(const string& key){
    vector<unsigned char> result(key.length()/2);
    for (int i = 0; i < key.length(); i+=2)
    {
        /* code */
        result[i/2]=dataConverter.convertFromHexadecimal2Decimal(key.substr(i,2));
    }
    return result;
    
}