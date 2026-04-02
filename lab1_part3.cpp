#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;
int main() {
    ifstream infile("GettysburgAddress.txt");

    if (!infile) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    string word;
    
    while (infile >> word) {
        string cleaned = "";

        for (int i = 0; i < word.length(); i++) {
            if (isalpha(word[i])) {
                cleaned += toupper(word[i]);
            }
        }

        if (cleaned.length() >= 10) {
            cout << cleaned << endl;
        }
    }

    infile.close();
    return 0;
}