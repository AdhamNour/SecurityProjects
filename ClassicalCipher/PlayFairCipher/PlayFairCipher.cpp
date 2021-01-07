#include "PlayFairCipher.h"
void PlayFairCipher::setKey(const string &key)
{
    if (this->key != key)
    {
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
            this->keyTable->push_back(vector<char>(x));
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
            this->keyTable->push_back(vector<char>(x));
            x.clear();
        }
        x.push_back(i);
    }
    this->keyTable->push_back(vector<char>(x));
    x.clear();
}

string PlayFairCipher::encrypte(const string &plaintext)
{
    string plaintext_with_no_spaces = this->removeSpaces(plaintext);            //remove any spaces in the plaintext string
    string plaintext_with_no_dublication = this->removeDublications(plaintext); //remove any possible dublications in the plaintext string , if x is dublicated then the leter below it would be inserted;
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

string PlayFairCipher::removeDublications(const string &str)
{
    string result(str);
    pair<int, int> x_position(-1, -1);
    for (int i = 0; i < result.length() - 1; i++)
    {
        if (result[i] == result[i + 1])
        {
            if (result[i] == 'x')
            {
                if (x_position.first == -1)
                {
                    //search for the x in the key keyTable
                    x_position = this->findPosition('x');
                    /**
                     * we can set that x posistion while setting the key but this would be done in the next iteration of development of that algorithm
                    */
                }
                if (result[i] == 'j')
                {
                    result[i] = 'i';
                    result[i + 1] = 'i';
                }
                result.insert(i, " " + this->keyTable->at((x_position.first + 1) % 5)[x_position.second]);
            }
            else
            {
                result.insert(i, "x");
            }
        }
    }
    if(result.length()%2 ==1){
        result.push_back('x');
    }
    return result;
}

pair<int, int> PlayFairCipher::findPosition(const char &target)
{
    char Target(target);
    if (Target == 'j')
        Target = 'i';
    for (int i = 0; i < this->keyTable->size(); i++)
        for (int j = 0; j < this->keyTable->at(i).size(); j++)
            if (this->keyTable->at(i).at(j) == target)
                return pair<int, int>(i, j);
}