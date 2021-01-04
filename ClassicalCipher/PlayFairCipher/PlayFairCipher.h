#ifndef PLAY_FAIR_CIPHER
#define PLAY_FAIR_CIPHER
#include<string>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
class PlayFairCipher
{
private:
    string key = "";
    vector<vector<char> >* keyTable =  NULL;
    void setKeyTable();
public:
    PlayFairCipher(string key){setKey(key);}
    ~PlayFairCipher();
    void setKey(const string& key);
};



string playFairCipher(string plaintext,string key);
#endif