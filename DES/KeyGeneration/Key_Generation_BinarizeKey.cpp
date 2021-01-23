#include "KeyGeneration.h"
#include "../DataConverter/DataConverter.h"

void KeyGeneration::BinarizeKey(const string& key, string& key_bin) {
    DataConverter dconverter;
    for (auto &&i : key)
    {
        key_bin += dconverter.convertFromHexadecimal2Binary(i);
    }
}