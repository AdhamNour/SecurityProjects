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
    vector<unsigned char> newTarget(target.size());
    int i = 0;
    for (size_t j = 0; j < 4; j++)
    {
        for (size_t k = 0; k < rows[j].size(); k++)
        {
            newTarget[i++] = rows[j][k];
        }
        
    }
    return newTarget;    
}