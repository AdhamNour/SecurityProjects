#include "../../../AES.hpp"
#include "../../../AES_Utils/AES_Utils.hpp"
#include "Inverse_Mix_Column_Matrix/Inverse_Mix_Column_Matrix.hpp"
#include "../../GALOIS_MULTIP/GALOIS_MULTIP.hpp"
vector<unsigned char> AES::InverseMixColomns(const vector<unsigned char> &target)
{
    vector<unsigned char> newTarget, r(4), c(4);
    vector<unsigned char> MIX_COLUMN_MATRIX_VECTOR(INVERSE_MIX_COLUMN_MATRIX, INVERSE_MIX_COLUMN_MATRIX + 16);
    GALOIS_MULTIP galois_multip;
    for (int i = 0; i < 16; i++)
    {
        AES_Utils::sliceVector(MIX_COLUMN_MATRIX_VECTOR, r, (i % 4) * 4);
        AES_Utils::sliceVector(target, c, i - i % 4);
        unsigned char result = 0;
        for (int j = 0; j <4;j++)
            if(r[j]==1)
                result ^= c[j];
            else
                result ^= galois_multip.get(r[j],c[j]);
        newTarget.push_back(result);
    }
    return newTarget;

    return newTarget;
}