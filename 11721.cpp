#include <iostream>
#include <string>

using namespace std;

int main(){
    int i;
    string str;
    cin >> str;
    for(i=0;i<str.length();i++){
        cout << str[i];
        if(i%10==9)cout << '\n';
    }
    if(i%10!=0){
        cout << '\n';
    }
    return 0;
}