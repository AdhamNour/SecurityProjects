#include<string>
#include<vector>
using namespace std;

#include "../../DataConverter/DataConverter.h"

class KeyGeneration
{
private:
    DataConverter dataConverter;
    vector<unsigned char> getTheDecimalArrayFromHexadeciaml(const string& key);
public:
    vector<vector<unsigned char> > genrtateKeys(const string& key);
};
