#include <iostream>
#include <string>

using namespace std;

constexpr long long mod_n = 1234567891;
long long r[50]={};

int main(){
    string str;
    int res=0,t;
    cin >> t;
    cin >> str;
    r[0]=1;
    for(int i=1;i<50;i++){
        r[i]=(r[i-1]*31)%mod_n;
    }
    for(int i=0;i<str.length();i++){
        res = (res + (str[i]-'a'+1)*r[i])%mod_n;
    }
    cout << res << endl;
    return 0;
}