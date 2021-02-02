#include <iostream>
#include<fstream>
#include<string>
using namespace std;

void CaeserCipher();
void hillCipher();
void playFairCipher();
void vernamCipher();
void VignereCipher();

int main(void){
    cout<<"Enter the Cipher you want to try"<<endl;
    cout<<"1.Caeser Cipher"<<endl;
    cout<<"2.Hill Cipher"<<endl;
    cout<<"3.PlayFair Cipher"<<endl;
    cout<<"4.Vernam Cipher"<<endl;
    cout<<"5.Vigenere Cipher"<<endl;
    cout<<"choose the result based on the number beside it"<<endl;
    
    int userChoice; cin>>userChoice;
    switch (userChoice)
    {
    case 1:
        CaeserCipher();
        break;
    case 2:
        hillCipher();
        break;
    case 3:
        playFairCipher();
        break;
    case 4:
        vernamCipher();
        break;
    case 5:
        VignereCipher();
        break;
    default:
        cout<<"wrong choice try again"<<endl;
        break;
    }

    
    return 0;
}

void CaeserCipher(){
    
}