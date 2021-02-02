#ifndef PLAY_FAIR_CIPHER
#define PLAY_FAIR_CIPHER
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<sstream>
#include<map>
using namespace std;
class PlayFairCipher
{
private:
    string key = "";
    vector<vector<char> > keyTable ;
    void setKeyTable();
    string removeSpaces(const string& str);
    string removePairDublications(const string& str);
    pair<int,int> findPosition (const char& target);
public:
    PlayFairCipher(const string& key){setKey(key); }
    void setKey(const string& key);
    string encrypte(const string& plaintext);
};



string playFairCipher(string plaintext,string key);
#endif