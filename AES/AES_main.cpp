#include <iostream>
#include <string>

#include "AES.hpp"
using namespace std;
int main(void) {
    string key, plaintext;
    while (key.length() != 32)
    {
        cout << "enter a valid key with length 32 in hexadecimal format" << endl;
        cin >> key;
        for (auto &&i : key)
        {
            i = toupper(i);
        }
    }
    while (plaintext.length() != 32)
    {
        cout << "enter a valid target text with length 32 in hexadecimal format" << endl;
        cin >> plaintext;
        for (auto &&i : plaintext)
        {
            i = toupper(i);
        }
    }
    AES aes ;
    cout<<"[E]ncrypt or [D]ecryot"<<endl;
    char x;
    cin>>x;
    x=toupper(x);
    if(x=='E'){
        cout<<aes.encrypt(plaintext,key)<<endl;
    }
    else if (x=='D')
    {
        cout<<aes.decrypt(plaintext,key);
    }
    return 0;
}