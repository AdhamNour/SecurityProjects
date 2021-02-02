#include "../../AES.hpp"
#include "../../AES_Utils/AES_Utils.hpp"
#include "../../KeyGeneration/KeyGeneration.hpp"
#include "../../DataConverter/DataConverter.h"
string AES::encrypt(const string &plaintext, const string &key)
{
    KeyGeneration keyGeneration;
    DataConverter dataConverter;
    auto keys = keyGeneration.genrtateKeys(key);
    auto block = AES_Utils::getTheDecimalArrayFromHexadeciaml(plaintext);
    block = AES_Utils::xorLists(block, keys[0]);
    for (int round = 0; round < 10; round++)
    {
        AES_Utils::SubBytes(block);
        block = shiftRows(block);
        if (round != 9)
        {
            block = mixColomns(block);
        }
        block = AES_Utils::xorLists(block, keys[round + 1]);
    }
    string ciphertext;
    for (auto &&i : block)
    {
        ciphertext += dataConverter.convertFromDecimal2Binary((int)i);
    }
    return dataConverter.Hexadecimalize(ciphertext);
}