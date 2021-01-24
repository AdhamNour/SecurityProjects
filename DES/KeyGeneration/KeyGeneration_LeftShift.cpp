#include "KeyGeneration.h"

void KeyGeneration::left_shift(string& str, const int& n) {
    str =str.substr(n)+str.substr(0,n);
}