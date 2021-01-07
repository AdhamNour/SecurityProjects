#ifndef PLAY_FAIR_CIPHER
#define PLAY_FAIR_CIPHER
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<sstream>
using namespace std;
class PlayFairCipher
{
private:
    string key = "";
    vector<vector<char> >* keyTable =  NULL;
    void setKeyTable();
    string removeSpaces(const string& str);
    string removeDublications(const string& str);
    pair<int,int> findPosition (const char& target);
public:
    PlayFairCipher(string key){setKey(key);}
    ~PlayFairCipher();
    void setKey(const string& key);
    string encrypte(const string& plaintext);
};



string playFairCipher(string plaintext,string key);
#endif