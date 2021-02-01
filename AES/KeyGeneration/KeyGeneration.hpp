#include<string>
#include<vector>
using namespace std;

#include "../../DataConverter/DataConverter.h"

class KeyGeneration
{
public:
    vector<vector<unsigned char> > genrtateKeys(const string& key);
};
