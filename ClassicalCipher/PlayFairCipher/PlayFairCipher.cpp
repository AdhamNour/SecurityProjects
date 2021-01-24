#include "PlayFairCipher.h"
void PlayFairCipher::setKey(const string &key)
{
    if (this->key != key)
    {
        this->keyTable.clear();
        this->key = key;     //set the key with the new key
        this->setKeyTable(); //setup the new keyTable
    }
}

void PlayFairCipher::setKeyTable()
{
    string str(this->key);
    vector<char> x;
    set<char> passwordCharacterSet;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'j')
            str[i] = 'i';
        if (passwordCharacterSet.find(str[i]) == passwordCharacterSet.end())
        {
            passwordCharacterSet.insert(str[i]);
            x.push_back(str[i]);
        }
        if (x.size() >= 5)
        {
            this->keyTable.push_back(vector<char>(x));
            x.clear();
        }
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (i == 'j' || passwordCharacterSet.find(i) != passwordCharacterSet.end())
        {
            continue;
        }
        if (x.size() >= 5)
        {
            this->keyTable.push_back(vector<char>(x));
            x.clear();
        }
        x.push_back(i);
    }
    this->keyTable.push_back(vector<char>(x));
    x.clear();
}

string PlayFairCipher::encrypte(const string &plaintext)
{
    string plaintext_with_no_spaces = this->removeSpaces(plaintext);                                    //remove any spaces in the plaintext string
    string plaintext_with_no_pair_dublication = this->removePairDublications(plaintext_with_no_spaces); //remove any possible dublications in the plaintext string , if x is dublicated then the leter below it would be inserted;
    
    pair<int,int> firstCharacterIndex, secondCharacterIndex;
    for (int i = 0; i < plaintext_with_no_pair_dublication.length(); i+=2)
    {
        firstCharacterIndex = findPosition(plaintext_with_no_pair_dublication[i]);
        secondCharacterIndex = findPosition(plaintext_with_no_pair_dublication[i+1]);
        if(firstCharacterIndex.first ==secondCharacterIndex.first){
            plaintext_with_no_pair_dublication[i] = this->keyTable[firstCharacterIndex.first][(firstCharacterIndex.second+1)%5];
            plaintext_with_no_pair_dublication[i+1] = this->keyTable[secondCharacterIndex.first][(secondCharacterIndex.second+1)%5];
        }
        else if(firstCharacterIndex.second == secondCharacterIndex.second){
            plaintext_with_no_pair_dublication[i] = this->keyTable[(firstCharacterIndex.first+1)%5][firstCharacterIndex.second];
            plaintext_with_no_pair_dublication[i+1] = this->keyTable[(secondCharacterIndex.first+1)%5][secondCharacterIndex.second];
        }
        else{
            plaintext_with_no_pair_dublication[i] = this->keyTable[firstCharacterIndex.first][secondCharacterIndex.second];
            plaintext_with_no_pair_dublication[i+1] = this->keyTable[secondCharacterIndex.first][firstCharacterIndex.second];
        }
    }
    return plaintext_with_no_pair_dublication;
    
}

string PlayFairCipher::removeSpaces(const string &str)
{
    //The function should remove all the spaces in the input string
    string result, temp;
    stringstream ss;
    ss << str;
    while (ss >> temp)
        result += temp;
    return result;
}

string PlayFairCipher::removePairDublications(const string &str)
{
    /**
     * this function should remove any pair dublications
     * this function should also replace any 'j' with 'i'
     * this function should make the length of the string even
    */
    string result(str);
    pair<int, int> x_position(-1, -1);
    string x_inserstion;
    for (int i = 0; i < result.length(); i += 2)
    {
        if (result[i] == 'j')
        {
            result[i] = 'i';
        }
        if (result[i + 1] == 'j')
        {
            result[i + 1] = 'i';
        }
        if (result[i] == result[i + 1])
        {
            if (result[i] != 'x')
                result.insert(i + 1, "x");
            else
            {
                if (x_position.first == -1)
                {
                    x_position = this->findPosition('x');
                    x_inserstion.push_back(this->keyTable[(x_position.first + 1) % 5][x_position.second]);
                }
                result.insert(i + 1, x_inserstion);
            }
        }
    }
    if (result.length() % 2 == 1)
    {
        result += "x";
    }
    return result;
}

pair<int, int> PlayFairCipher::findPosition(const char &target)
{
    char Target(target);
    if (Target == 'j')
        Target = 'i';
    for (int i = 0; i < this->keyTable.size(); i++)
        for (int j = 0; j < this->keyTable.at(i).size(); j++)
            if (this->keyTable.at(i).at(j) == target)
                return pair<int, int>(i, j);
    return pair<int, int>(-1, -1); //This case supposed to be not reached
}