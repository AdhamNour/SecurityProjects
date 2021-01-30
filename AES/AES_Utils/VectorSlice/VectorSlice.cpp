#include "VectorSlice.hpp"
void sliceVector(const vector<unsigned char>& originalVector,
    vector<unsigned char>& result,
    const int&startWith){
        for (int i = startWith; i < startWith + result.size(); i++)
        {
            result[i-startWith] = originalVector[i];
        }
        
}