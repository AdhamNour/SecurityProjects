#include "../../AES.hpp"
#include "../../AES_Utils/AES_Utils.hpp"
#include "../../KeyGeneration/KeyGeneration.hpp"
#include "../../../DataConverter/DataConverter.h"

#include <algorithm>

string AES::decrypt(const string &ciphertext, const string &key)
{
    KeyGeneration keyGeneration;
    DataConverter dataConverter;
    auto keys = keyGeneration.genrtateKeys(key);
    reverse(keys.begin(),keys.end());
    auto block = AES_Utils::getTheDecimalArrayFromHexadeciaml(ciphertext);
    block = AES_Utils::xorLists(block, keys[0]);
    for (int round = 0; round < 10; round++)
    {
        AES_Utils::InverseSubBytes(block);
        block = InverseShiftRows(block);
        if (round != 9)
        {
            block = InverseMixColomns(block);
            block = AES_Utils::xorLists(block, InverseMixColomns(keys[round + 1]));

        }
        else
        {
            /* code */
            block = AES_Utils::xorLists(block, keys[round + 1]);

        }
        
    }
    string plaintext;
    for (auto &&i : block)
    {
        plaintext += dataConverter.convertFromDecimal2Binary((int)i);
    }
    return dataConverter.Hexadecimalize(plaintext);
}