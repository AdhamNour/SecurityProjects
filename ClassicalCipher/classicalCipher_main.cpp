#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "CaeserCipher/CaeserCipher.h"
#include "HillCipher/HillCipherWrapper/HillCipherWrapper.hpp"
#include "PlayFairCipher/PlayFairCipherWrapper/PlayFairCipherWrapper.hpp"
#include "VernamCipher/VernamCipherWrapper/VernamCipherWrapper.hpp"
#include "VigenereCipher/VigenereCipher.h"

using namespace std;

void CaeserCipher();
void hillCipher();
void playFairCipher();
void vernamCipher();
void VignereCipher();

int main(void)
{
    cout << "Enter the Cipher you want to try" << endl;
    cout << "1.Caeser Cipher" << endl;
    cout << "2.Hill Cipher" << endl;
    cout << "3.PlayFair Cipher" << endl;
    cout << "4.Vernam Cipher" << endl;
    cout << "5.Vigenere Cipher" << endl;
    cout << "choose the result based on the number beside it" << endl;

    int userChoice;
    cin >> userChoice;
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
        cout << "wrong choice try again" << endl;
        break;
    }

    return 0;
}

void CaeserCipher()
{
    cout << "Hello in Caeser Cipher" << endl;
    while (1)
    {
        string file_path;
        cout << "please specify the input file path with no spaces: ";
        cin >> file_path;
        ifstream input_file(file_path);
        if (input_file.is_open())
        {
            ofstream myfile[3];
            cout << "please specify the output file path with no spaces,extention or nesting folder: ";
            cin >> file_path;
            int keys[3] = {3, 6, 12};
            for (auto &&i : myfile)
            {
                file_path.push_back('I');
                i.open(file_path + ".txt");
            }
            string inputData;

            while (getline(input_file, inputData))
            {
                for (int i = 0; i < 3; i++)
                {
                    myfile[i] << caeserCipher(inputData, keys[i]);
                }
            }

            for (auto &&i : myfile)
            {
                i.close();
            }
            break;
        }
        else
            cout << "theres some error occured try again" << endl;
    }
}

void hillCipher()
{
    cout << "Choose the Key size: ";
    int n;
    cin >> n;
    vector<vector<char> >key;
    if (n == 2)
        key ={{5, 17},
                          {8, 3}};
    else if (n == 3)
        key = {{2, 4, 12},
                          {9, 1, 6},
                          {7, 5, 3}};
    while (1)
    {
        string file_path;
        cout << "please specify the input file path with no spaces: ";
        cin >> file_path;
        ifstream input_file(file_path);
        if (input_file.is_open())
        {
            ofstream myfile;
            cout << "please specify the output file path with no spaces or nesting folder: ";
            cin >> file_path;
            myfile.open(file_path);
            string inputData;
            while (getline(input_file, inputData))
            {
                myfile << hill_cipher(inputData,key)<<endl;
            }
            myfile.close();
            break;
        }
        else
            cout << "theres some error occured try again" << endl;
    }
}

void playFairCipher(){
    while (1)
    {
        string file_path;
        cout << "please specify the input file path with no spaces: ";
        cin >> file_path;
        ifstream input_file(file_path);
        if (input_file.is_open())
        {
            ofstream myfile_rats,myfile_archangles;
            cout << "please specify the output file path with no spaces, extention or nesting folder: ";
            cin >> file_path;
            myfile_rats.open(file_path+"_rats.txt");
            myfile_archangles.open(file_path+"_archangles.txt");
            string inputData;
            while (getline(input_file, inputData))
            {
                myfile_rats << playfair(inputData,"rats" )<<endl;
                myfile_archangles << playfair(inputData,"archangles" )<<endl;

            }
            myfile_archangles.close();
            myfile_rats.close();
            break;
        }
        else
            cout << "theres some error occured try again" << endl;
    }
}

void vernamCipher(){
    while (1)
    {
        string file_path;
        cout << "please specify the input file path with no spaces: ";
        cin >> file_path;
        ifstream input_file(file_path);
        if (input_file.is_open())
        {
            ofstream myfile;
            cout << "please specify the output file path with no spaces, or nesting folder: ";
            cin >> file_path;
            myfile.open(file_path);
            string inputData;
            while (getline(input_file, inputData))
            {
                myfile << vernam_ciper(inputData,"SPARTANS")<<endl;
            }
            myfile.close();
            break;
        }
        else
            cout << "theres some error occured try again" << endl;
    }
}

void VignereCipher(){
    while (1)
    {
        string file_path;
        cout << "please specify the input file path with no spaces: ";
        cin >> file_path;
        ifstream input_file(file_path);
        if (input_file.is_open())
        {
            ofstream myfile_pie,myfile_aether;
            cout << "please specify the output file path with no spaces, extention or nesting folder: ";
            cin >> file_path;
            myfile_pie.open(file_path+"_pie.txt");
            myfile_aether.open(file_path+"_aether.txt");
            string inputData;
            while (getline(input_file, inputData))
            {
                myfile_pie << vigenereCihper(inputData,"pie",false)<<endl;
                myfile_aether <<vigenereCihper(inputData,"aether",true)<<endl;

            }
            myfile_aether.close();
            myfile_pie.close();
            break;
        }
        else
            cout << "theres some error occured try again" << endl;
    }
}