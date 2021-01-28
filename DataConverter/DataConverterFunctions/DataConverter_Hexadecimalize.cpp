#include "../DataConverter.h"

string DataConverter::Hexadecimalize(const string & target){
    string result((target.length()/4),'0');
    for (int i = 0; i < target.length(); i+=4)
    {
        result[i/4] = convertFromBinary2Hexadecimal(target.substr(i,4));
    }
    return result;
}