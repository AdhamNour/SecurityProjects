#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <stdlib.h>

#include "DES/DataConverter/DataConverter.h"

using namespace std;
int main(void)
{
    DataConverter dconverter;
    cout<<dconverter.convertFromHexadecimal2Binary('F')<<endl;
    return 0;
}