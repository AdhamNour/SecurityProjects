#include <iostream>
#include <string>

#include "DES.h"
using namespace std;
int main(void)
{
    string key, plaintext;
    while (key.length() != 16)
    {
        cout << "enter a valid key with length 16 in hexadecimal format" << endl;
        cin >> key;
        for (auto &&i : key)
        {
            i = toupper(i);
        }
    }
    while (plaintext.length() != 16)
    {
        cout << "enter a valid target text with length 16 in hexadecimal format" << endl;
        cin >> plaintext;
        for (auto &&i : plaintext)
        {
            i = toupper(i);
        }
    }
    DES des;
    cout << "[E]ncrypt or [D]ecryot" << endl;
    char x;
    cin >> x;
    int n;
    cout << "Please enter the number of times you wanna me apply that DES operation using that key" << endl;
    cin >> n;
    x = toupper(x);
    string result(plaintext);
    for (int i = 0; i < n; i++)
    {
        if (x == 'E')
        {
            result = des.encrypt(result, key);
        }
        else if (x == 'D')
        {
            result = des.encrypt(result, key);
        }
    }
    cout<<result<<endl;
}