#include "DataConverter.h"

string DataConverter::convertFromDecimal2Binary(int target)
{
    string binaryNum(8, '0');
    // counter for binary array
    int i = 7;
    while (target > 0)
    {
        // storing remainder in binary array
        if (target % 2 == 1)
            binaryNum[i] = '1';
        else
            binaryNum[i] = '0';
        target = target / 2;
        i--;
    }
    return binaryNum;
}

int DataConverter::convertFromBinary2Decimal(const string &target)
{
    int result = 0;
    int multiplier = 1;
    for (int i = target.length() - 1; i >= 0; i--)
    {
        if (target[i] == '1')
        {
            result += multiplier;
        }
        multiplier *= 2;
    }
    return result;
}

string DataConverter::convertFromHexadecimal2Binary(const char &target)
{
    return convertFromDecimal2Binary(DataConverter::hexa.find(target)).substr(4);
}

char DataConverter::convertFromDecimal2Hexadecimal(const int &target)
{
    return DataConverter::hexa[target];
}

char DataConverter::convertFromBinary2Hexadecimal(const string &target){
    return convertFromDecimal2Hexadecimal(convertFromBinary2Decimal(target));
}