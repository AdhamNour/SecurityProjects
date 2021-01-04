#include <iostream>
#include <vector>
#include <string>
#include <set>

//#include "ClassicalCipher/CaeserCipher/CaeserCipher.h"
using namespace std;
int main(void)
{
    string str = "jadhamn";
    vector<vector<char>> _vector;
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
            _vector.push_back(vector<char>(x));
            x.clear();
        }
    }

    for (char i = 'a'; i <= 'z'; i++)
    {
        if (i == 'j' || passwordCharacterSet.find(i)!=passwordCharacterSet.end())
        {
            continue;
        }

        if (x.size() >= 5)
        {
            _vector.push_back(vector<char>(x));
            x.clear();
        }
        x.push_back(i);
    }
    _vector.push_back(vector<char>(x));
    x.clear();
    for (int i = 0; i < _vector.size(); i++)
    {
        for (int j = 0; j < _vector[i].size(); j++)
        {
            cout << _vector[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}