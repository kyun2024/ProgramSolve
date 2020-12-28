#include <iostream>
#include <string>

using namespace std;

constexpr int mod_n = 20000303;

int main(){
    int i,d,r=0;
    string str;
    cin >> str;
    for(i=0,d=1;i<str.length();i++,d=(10*d)%mod_n){
        int place = str[str.length()-i-1]-'0';
        r = (r + place*d)%mod_n;
    }
    cout << r << endl;
    return 0;
}