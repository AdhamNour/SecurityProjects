#ifndef DATA_CONVERTER
#define DATA_CONVERTER
#include <string>
using namespace std;

class DataConverter
{
private:
    inline static string hexa;
    char convertFromDecimal2Hexadecimal(const int &target)
    {
        return DataConverter::hexa[target];
    }

public:
    DataConverter()
    {
        hexa = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    };
    string convertFromDecimal2Binary(int target);
    int convertFromBinary2Decimal(const string &target);
    string convertFromHexadecimal2Binary(const char &target);
    char convertFromBinary2Hexadecimal(const string &target);
};

#endif