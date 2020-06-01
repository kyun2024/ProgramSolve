#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin >> s;
    if(s.length()==3){
        cout << 10+s[(s[1]=='0')*2]-'0' << endl;
    }
    else if(s.length()==4){
        cout << 20 << endl;
    }
    else{
        cout << s[0]+s[1]-2*'0' << endl;
    }
    return 0;
}