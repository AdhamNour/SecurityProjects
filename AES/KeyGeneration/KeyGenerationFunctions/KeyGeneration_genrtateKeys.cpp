#include "../KeyGeneration.hpp"
#include "../KeyGenerationConstants/RoundConstants.hpp"

#include "../../AES_Utils/AES_Utils.hpp"


#include <iostream>
vector<vector<unsigned char>> KeyGeneration::genrtateKeys(const string &key)
{
    if (key.length() != 32)
    {
        cerr << "The key is not 128 bit, sadly this algorithm is designed only to work on 128 bit" << endl;
        return {}; //return an empty vector as asign to generation failer
    }
    vector<unsigned char> AES_Key = AES_Utils::getTheDecimalArrayFromHexadeciaml(key);
    vector<vector<unsigned char>> keys(11);
    keys[0] = AES_Key;
    for (int i = 0; i < keys.size() - 1; i++)
    {
        vector<unsigned char> PreviousKey(keys[i]), row0(4), rcon = {(unsigned char)RoundConstants[i], 0, 0, 0};
        AES_Utils::sliceVector(PreviousKey, row0, 12);
        AES_Utils::rotate(row0); //rotate the key
        AES_Utils::SubBytes(row0);
        vector<unsigned char> prevKey(4);
        AES_Utils::sliceVector(PreviousKey, prevKey, 0);
        vector<unsigned char> currentKey(AES_Utils::xorLists(AES_Utils::xorLists(prevKey, row0), rcon));
        vector<unsigned char> currRow(4), prevRow(4), temp;
        for (int j = 0; j < 3; j++)
        {
            AES_Utils::sliceVector(currentKey, currRow, j * 4);
            AES_Utils::sliceVector(PreviousKey, prevRow, j * 4 + 4);
            temp = AES_Utils::xorLists(prevRow, currRow);
            currentKey.resize(currentKey.size(), 4);
            currentKey.insert(currentKey.end(), temp.begin(), temp.end());
        }
        keys[i + 1] = currentKey;
    }
    return keys;
}