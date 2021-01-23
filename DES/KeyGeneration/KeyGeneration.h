#ifndef KEY_GENERATION
#define KEY_GENERATION
#include <vector>
#include <string>
using namespace std;
class KeyGeneration
{
private:
    void BinarizeKey(const string& key , string&key_bin);
    void compriseKey(const string& key_bin, string&C,string&D);
    void left_shift(string&str ,const int&n);
public:
    vector<string> generateKeys(const string& key);
};
#endif