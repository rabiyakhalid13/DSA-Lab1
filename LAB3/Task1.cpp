#include<iostream>
#include<string>
using namespace std;

bool isPalindrome(string str){
    int start=0;
    int end=str.length()-1;
    while(start<end){
        if (str[start]!=str[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main(){
    string str;
    cout<<"Enter a string"<<endl;
    cin>>str;
    if(isPalindrome(str)){
        cout<<"The string is Palindrome"<<endl;
    }
    else{
        cout<<"The string is not Palindrome"<<endl;
    }
    return 0;
}