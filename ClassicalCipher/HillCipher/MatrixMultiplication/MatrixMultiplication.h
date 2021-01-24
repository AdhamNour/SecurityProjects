/**
 * These function are not for normal matrix multiplication
 * they are tightly coupled with HillCipher
*/

#ifndef MATRIX_MULTIPLICATION
#define MATRIX_MULTIPLICATION
#include <iostream>
#include <vector>
using namespace std;
bool checkSquare(const vector<vector<char>> &x);
string multiply(const vector<vector<char>> &x, const string &y);
#endif