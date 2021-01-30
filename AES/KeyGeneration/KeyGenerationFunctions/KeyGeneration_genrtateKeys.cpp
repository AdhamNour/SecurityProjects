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
    vector<vector<unsigned char>> keys(10);
    keys[0] = AES_Key;
    for (int i = 0; i < keys.size() - 1; i++)
    {
        vector<unsigned char> PreviousKey(keys[i]), row0(4), rcon = {(unsigned char)RoundConstants[i], 0, 0, 0};
        //TODO: Remove The Printing Section
        print(PreviousKey, "Previous Key");
        print(row0, "row 0");
        print(rcon, "rcon");
        //End of printing section
        sliceVector(PreviousKey, row0, 12);
        //TODO: Remove The Printing Section
        print(row0, "row 0");
        //End of printing section
        rotate(row0); //rotate the key
                      //TODO: Remove The Printing Section
        print(row0, "row 0");
        //End of printing section
        SubBytes(row0);
        //TODO: Remove The Printing Section
        print(row0, "row 0");
        //End of printing section
        vector<unsigned char> prevKey(4);
        sliceVector(PreviousKey, prevKey, 0);
        //TODO: Remove The Printing Section
        print(prevKey, "prevKey");
        //End of printing section
        vector<unsigned char> currentKey(XOR(XOR(prevKey, row0), rcon));
        //TODO: Remove The Printing Section
        print(currentKey, "currentKey");
        //End of printing section
        vector<unsigned char> currRow(4), prevRow(4), temp;
        for (int j = 0; j < 3; j++)
        {
            sliceVector(currentKey, currRow, j * 4);
            //TODO: Remove The Printing Section
            print(currRow, "currRow");
            //End of printing section
            sliceVector(currentKey, prevRow, j * 4 + 4);
            //TODO: Remove The Printing Section
            print(prevRow, "prevRow");
            //End of printing section
            temp = XOR(prevRow, currRow);
            currentKey.resize(currentKey.size(), 4);
            currentKey.insert(currentKey.end(), temp.begin(), temp.end());
            //TODO: Remove The Printing Section
            print(currentKey,"currentKey");
        //End of printing section
        }
        keys[i + 1] = currentKey;
    }
    return keys;
}