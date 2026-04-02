#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main(){
    string input;
    string reversed = "";
    cout << "Please enter a string: ";
    cin >> input;
    for (int i = input.length()-1; i >= 0; i--){
        reversed += input[i];
    }
    for(int i = 0; i < 5; i++){
        cout << setw(input.length()+i) << input << setw(input.length() + 10) << reversed << endl;
    }
    return 0;
}