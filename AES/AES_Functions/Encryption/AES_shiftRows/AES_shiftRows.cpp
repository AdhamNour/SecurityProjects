#include "../../../AES.hpp"
#include "../../../AES_Utils/AES_Utils.hpp"
vector<unsigned char> AES::shiftRows(const vector<unsigned char>&target){
    vector<unsigned char> rows[4];
    vector<unsigned char> row;
    for (int i = 0; i < 4; i++)
    {
        AES_Utils::sliceVector(target,row,i,4);
        AES_Utils::rotate(row,i);
        rows[i]=row;
    }
    vector<unsigned char> newTarget;
    for (size_t j = 0; j < 4; j++)
    {
        for (size_t k = 0; k < rows[j].size(); k++)
        {
            newTarget.push_back(rows[k][j]);
        }
        
    }
    return newTarget;    
}