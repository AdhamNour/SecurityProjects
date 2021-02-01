#include<string>
#include<vector>
using namespace std;

#include "../../DataConverter/DataConverter.h"

class KeyGeneration
{
private:
    DataConverter dataConverter;
    vector<unsigned char> getTheDecimalArrayFromHexadeciaml(const string& key);
    //void rotate(vector<unsigned char>&target);
    vector<unsigned char> XOR (const vector<unsigned char>& target1, const vector<unsigned char>& target2);
public:
    void rotate(vector<unsigned char>&target);
    vector<vector<unsigned char> > genrtateKeys(const string& key);
};
