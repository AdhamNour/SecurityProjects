#ifndef HILL_CIPHER
#define HILL_CIPHER

#include "MatrixMultiplication/MatrixMultiplication.h"
#include <vector>
using namespace std;

class HillCipher
{
private:
    vector<vector<char> > key;
    void padTheString(string& str);
public:
    HillCipher(const vector<vector<char> >& key){setKey(key);}
    void setKey(const vector<vector<char> >& key);
    string encrypt(const string& plainText);
};

#endif