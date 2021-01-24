#include "../DataConverter.h"

void DataConverter::Binarize(const string& target , string& target_bin){
    for (auto &&i : target)
    {
        target_bin += convertFromHexadecimal2Binary(i);
    }
}