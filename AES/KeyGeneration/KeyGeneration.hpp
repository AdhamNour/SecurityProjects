#ifndef AES_KEY_GENERATION
#define AES_KEY_GENERATION
#include<string>
#include<vector>
using namespace std;

#include "../DataConverter/DataConverter.h"

class KeyGeneration
{
public:
    vector<vector<unsigned char> > genrtateKeys(const string& key);
};
#endif // !AES_KEY_GENERATION