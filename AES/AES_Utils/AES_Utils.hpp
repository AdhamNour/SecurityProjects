#ifndef AES_UTILS_FUNCTIONS
#define AES_UTILS_FUNCTIONS
#include<vector>
#include<string>
#include<iostream>
using namespace std;

#include "../../DataConverter/DataConverter.h"

class AES_Utils
{
private:
    inline static DataConverter dataConverter;
public:
    static void SubBytes(vector<unsigned char>& target);
    static vector<unsigned char> xorLists(const vector<unsigned char>&target1,const  vector<unsigned char>& target2);
    static void rotate(vector<unsigned char>& target,const int& amount=1);
    static void sliceVector(const vector<unsigned char>& originalVector,vector<unsigned char>& result,const int&startWith=0,const int& step=1);
    static vector<unsigned char> getTheDecimalArrayFromHexadeciaml(const string &target);
    static void print(vector<unsigned char> x, string name);
};


#endif