#include "BlockEncryptor.h"

BlockEncryptor::BlockEncryptor(){
    for (int i = 0; i < 64; i++)
    {
        inverse_permutation_table[InitialPermutation[i]-1] =i;
    }
    
}