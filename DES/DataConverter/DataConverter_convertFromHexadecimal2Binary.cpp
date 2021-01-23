#include "DataConverter.h"
string DataConverter::convertFromHexadecimal2Binary(const char &target)
{
    return convertFromDecimal2Binary(DataConverter::hexa.find(target)).substr(4);
}