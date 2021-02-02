#include "../../AES.hpp"
#include "Mix_Column_Matrix/Mix_Column_Matrix.hpp"
#include "../../AES_Utils/AES_Utils.hpp"
vector<unsigned char> AES::mixColomns(const vector<unsigned char>& target){
    vector<unsigned char> newTarget,r(4),c(4);
    vector<unsigned char> MIX_COLUMN_MATRIX_VECTOR(MIX_COLUMN_MATRIX,MIX_COLUMN_MATRIX+16);
    for (int i = 0; i < 16; i++)
    {
        AES_Utils::sliceVector(MIX_COLUMN_MATRIX_VECTOR,r,(i%4)*4);
        AES_Utils::print(r,"r");

        AES_Utils::sliceVector(target,c,i-i%4);
        AES_Utils::print(c,"c");
    }
    
    return newTarget;
}