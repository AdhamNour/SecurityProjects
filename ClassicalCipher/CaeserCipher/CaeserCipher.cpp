#include "CaeserCipher.h"

string caeserCipher(const string &plaintext, const int &key)
{
    string ciphertext(plaintext);
    for (int i = 0; i < ciphertext.length(); i++)
    {
        if (isalpha(ciphertext[i]))
        {
            char target = tolower(ciphertext[i]);                    // getting red of the capital latters
            int relativeDistance = (int)(target - 'a');              // calculating the distance from the beginning of the alphabet
            int newRelativeDistance = (relativeDistance + key) % 26; // calculating the new distance from the character 'a' taking in consideration the alphabet is circular
            ciphertext[i] = char(newRelativeDistance + 'a');         // assigning the ith character to the encrypted character
        }
    }
    return ciphertext;
}