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