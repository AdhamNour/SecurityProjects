#include "DataConverter.h"
char DataConverter::convertFromBinary2Hexadecimal(const string &target){
    return convertFromDecimal2Hexadecimal(convertFromBinary2Decimal(target));
}