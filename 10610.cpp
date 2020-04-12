#include <iostream>
#include <string>

using namespace std;

int c[10];

int main(){
    int s=0,i,j;
    string str;
    cin >> str;
    for(i=0;i<str.length();i++){
        s += str[i]-'0';
        c[str[i]-'0']+=1;
    }
    if(s%3!=0 || c[0]==0){
        cout << -1 << endl;
        return 0;
    }
    for(i=9;i>=0;i--){
        for(j=0;j<c[i];j++){
            cout << static_cast<char>(i+'0');
        }
    }
    cout << endl;
    return 0;
}