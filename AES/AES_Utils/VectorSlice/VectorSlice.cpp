#include "../AES_Utils.hpp"
void AES_Utils::sliceVector(
    const vector<unsigned char> &originalVector,
    vector<unsigned char> &result,
    const int &startWith,
    const int &step)
{
    for (int i = startWith; i < startWith + result.size(); i++)
    {
        //FIXME: need to be configured
        result[i - startWith] = originalVector[i];
    }
}