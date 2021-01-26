#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>

#include "./DES/DES.h"

using namespace std;
int main(void)
{
    DES des;
    cout<<des.encrypt("FFFFFFFFFFFFFFFF","0000000000000000")<<endl;
    return 0;
}