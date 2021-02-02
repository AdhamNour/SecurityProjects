#include "../AES_Utils.hpp"
void AES_Utils::sliceVector(
    const vector<unsigned char> &originalVector,
    vector<unsigned char> &result,
    const int &startWith,
    const int &step)
{
    int initalResultSize = result.size();
    int loopEnd;
    if(initalResultSize == 0)
        loopEnd = originalVector.size();
    else
        loopEnd = startWith + result.size()*step;
    for (int i = startWith; i < loopEnd ; i+=step)
    {
        //FIXME: need to be configured
    if(initalResultSize != 0){
        result[(i - startWith)/step] = originalVector[i];
    }
    else
    {
        result.push_back(originalVector[i]);
    }
    

    }
}