#include "../DataConverter.h"

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