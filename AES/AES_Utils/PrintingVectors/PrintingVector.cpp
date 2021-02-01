#include "../AES_Utils.hpp"
void AES_Utils::print(vector<unsigned char> x, string name)
{
    cout << "The " << name << " contains" << endl
            << '[';
    for (auto &&i : x)
    {
        cout << ' ' << (int)i;
    }
    cout << ']' << endl
            << endl;
}