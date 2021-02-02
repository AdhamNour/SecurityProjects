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
    DES des ;
    cout<<"[E]ncrypt or [D]ecryot"<<endl;
    char x;
    cin>>x;
    x=toupper(x);
    if(x=='E'){
        cout<<des.encrypt(plaintext,key)<<endl;
    }
    else if (x=='D')
    {
        cout<<des.decrypt(plaintext,key);
    }
}