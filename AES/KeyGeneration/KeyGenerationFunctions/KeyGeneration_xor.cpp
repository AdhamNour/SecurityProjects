#include "../KeyGeneration.hpp"
#include<iostream>

vector<unsigned char> KeyGeneration::xor (const vector<unsigned char>& target1, const vector<unsigned char>& target2){
    if(target1.size() != target2.size()){
        cerr << "There's error occured in \" KeyGeneration::xor\" targets \' are not equal "<<endl;
        return {};
    }
    vector<unsigned char> result(target1.size());
    for (int i = 0; i < result.size(); i++)
    {
        result[i] = target1[i]^target2[i];
    }
    return result;
}