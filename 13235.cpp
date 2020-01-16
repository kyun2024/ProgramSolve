#include <iostream>
#include <string>

using namespace std;

bool palindrome(string s){
    int i=0;
    for(i=0;i<s.length()/2;i++){
        if(s[i]!=s[s.length()-i-1]){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin >> s;
    cout << (palindrome(s)?"true":"false") << endl;
    return 0;
}