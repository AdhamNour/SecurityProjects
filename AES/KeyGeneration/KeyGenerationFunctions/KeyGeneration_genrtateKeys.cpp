#include "../KeyGeneration.hpp"
#include "../../AES_Constants/SBox/SBox.hpp"
#include "../KeyGenerationConstants/RoundConstants.hpp"

#include "../../AES_Utils/SubBytes/SubBytes.hpp"
#include "../../AES_Utils/VectorSlice/VectorSlice.hpp"
#include "../../AES_Utils/PrintingVectors/PrintingVector.hpp"

#include <iostream>
vector<vector<unsigned char>> KeyGeneration::genrtateKeys(const string &key)
{
    if (key.length() != 32)
    {
        cerr << "The key is not 128 bit, sadly this algorithm is designed only to work on 128 bit" << endl;
        return {}; //return an empty vector as asign to generation failer
    }
    vector<unsigned char> AES_Key = getTheDecimalArrayFromHexadeciaml(key);
    vector<vector<unsigned char>> keys(11);
    keys[0] = AES_Key;
    for (int i = 0; i < keys.size() - 1; i++)
    {
        vector<unsigned char> PreviousKey(keys[i]), row0(4), rcon = {(unsigned char)RoundConstants[i], 0, 0, 0};
        sliceVector(PreviousKey, row0, 12);
        rotate(row0); //rotate the key
        SubBytes(row0);
        vector<unsigned char> prevKey(4);
        sliceVector(PreviousKey, prevKey, 0);
        vector<unsigned char> currentKey(XOR(XOR(prevKey, row0), rcon));
        vector<unsigned char> currRow(4), prevRow(4), temp;
        for (int j = 0; j < 3; j++)
        {
            sliceVector(currentKey, currRow, j * 4);
            sliceVector(PreviousKey, prevRow, j * 4 + 4);
            temp = XOR(prevRow, currRow);
            currentKey.resize(currentKey.size(), 4);
            currentKey.insert(currentKey.end(), temp.begin(), temp.end());
        }
        keys[i + 1] = currentKey;
    }
    return keys;
}