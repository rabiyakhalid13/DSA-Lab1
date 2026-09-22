#include <iostream>
#include <string>
using namespace std;

// task 1: program to check if a string is a palindrome

bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;

    // we compare characters from both ends
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true; // when all the characters match
}

int main() {
    string userInput;

    cout << "Enter a string: ";
    getline(cin, userInput);

    if (isPalindrome(userInput)) {
        cout << userInput << " is a palindrome." << endl;
    } else {
        cout << userInput << " is not a palindrome." << endl;
    }

    return 0;
}