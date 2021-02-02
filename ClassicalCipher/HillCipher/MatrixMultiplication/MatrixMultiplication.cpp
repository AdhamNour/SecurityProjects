#include "MatrixMultiplication.h"
#include <iostream>

bool checkSquare(const vector<vector<char>> &x)
{
    for (int i = 0; i < x.size(); i++)
    {
        if (x.size() != x[i].size())
        {
            cout << x.size() << '\t' << x[i].size() << '\t' << i << '\n';
            return false;
        }
    }
    return true;
}

string multiply(const vector<vector<char>> &x, const string &y)
{
    if (!(checkSquare(x) && x.size() == y.size()))
    {
        throw "not multiplicable";
        return NULL;
    }
    string result;
    for (int i = 0; i < x.size(); i++)
    {
        char sum = 0;
        for (int j = 0; j < x[i].size(); j++)
            sum += (x[i][j] * y[j])%26;
        result += ('a' + sum%26);
    }
    return result;
}