#include "../DataConverter.h"
char DataConverter::convertFromBinary2Hexadecimal(const string &target){
    return convertFromDecimal2HexadecimalDegit(convertFromBinary2Decimal(target));
}