#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str){
    if(str.length()<=1){
        return true;
    }
    if(str.front()==str.back()){
        return isPalindrome(str.substr(1,str.length()-2));
    }
    else return false;
}

int main(){
    string str;
    cin >> str;
    cout << isPalindrome(str) << endl;
    return 0;
}