#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>

#include "./DES/DES.h"

using namespace std;
//ABCDEDCBA5432ACB
int main(void)
{
    DES des;
    cout<<des.encrypt("ABC00F0ABCDEDCBA5432ACB","ABCDEDCBA5432ACB");
    return 0;
}