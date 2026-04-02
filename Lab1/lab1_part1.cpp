#include <iostream>
#include <string>
#include <cctype>
using namespace std;


void count(const string& text){
    int alnumCount = 0;
    int nonAlnumCount = 0;
    for(int i = 0; i < text.length(); i++){
        if (isalnum(text[i])){
            alnumCount++;
        }
        else if(text[i] != ' '){
            nonAlnumCount++;
        }
    }
    cout << text << " has " << alnumCount << " alphanumeric characters and " << nonAlnumCount << " nonalphanumeric characters\n";
}


int main(){
    string text;
    cout << "Please type something: ";
    getline(cin, text);
    count(text);
    return 0;
}