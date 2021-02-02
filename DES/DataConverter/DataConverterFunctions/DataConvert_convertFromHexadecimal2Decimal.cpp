#include "../DataConverter.h"

unsigned char DataConverter::convertFromHexadecimal2Decimal(const string &target)
{
    string target_bin;
    Binarize(target,target_bin);
    return convertFromBinary2Decimal(target_bin);
}