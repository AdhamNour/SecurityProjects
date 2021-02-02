#include "../DataConverter.h"

string DataConverter::convertFromDecimal2Hexadecimal(const int &target)
{
    return Hexadecimalize(convertFromDecimal2Binary(target));
}