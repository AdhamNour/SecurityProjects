#include<string>
#include<vector>
using namespace std;

#include "../../DataConverter/DataConverter.h"

class KeyGeneration
{
private:
    DataConverter dataConverter;
    vector<unsigned char> getTheDecimalArrayFromHexadeciaml(const string& key);
    void rotate(vector<unsigned char>&target);
    vector<unsigned char> xor (const vector<unsigned char>& target1, const vector<unsigned char>& target2);
public:
    vector<vector<unsigned char> > genrtateKeys(const string& key);
};
