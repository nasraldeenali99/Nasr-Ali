#include <iostream>
#include <string>
using namespace std;


// Function to encrypt a single character
char encrypttext(char ch, int a, int b) {
    if (isalpha(ch)) {
        int x = toupper(ch) - 'A';
        return (char)(((a * x + b) % 26) + 'A');
    }
    return ch;
}

// Function to decrypt a single character
char decrypttext(char ch, int c, int b) {
    if (isalpha(ch)) {
        int y = toupper(ch) - 'A';
        int result = c * (y - b);
        while (result < 0) {
            result += 26;
        }
        return (char)((result % 26) + 'A');
    }
    return ch;
}

// Function to perform encryption on a string
string encrypttext(const string& plainText, int a, int b) {
    string cipherText = "";
    for (char ch : plainText) {
        cipherText += encrypttext(ch, a, b);
    }
    return cipherText;
}

// Function to perform decryption on a string
string decrypttext(const string& cipherText, int c, int b) {
    string plainText = "";
    for (char ch : cipherText) {
        plainText += decrypttext(ch, c, b);
    }
    return plainText;
}

int main() {
    // Parameters
    int a, b, c;

    // Input parameters
    cout << "Enter parameter 'a': ";
    cin >> a;
    cout << "Enter parameter 'b': ";
    cin >> b;
    cout << "Enter parameter 'c' satisfying (a * c) mod 26 = 1: ";
    cin >> c;

    // Input text
    string plainText;
    cout << "Enter text to encrypt: ";
    cin.ignore();
    getline(cin, plainText);

    // Encryption
    string cipherText = encrypttext(plainText, a, b);
    cout << "Encrypted text: " << cipherText << endl;

    // Decryption
    string decryptedText = decrypttext(cipherText, c, b);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
