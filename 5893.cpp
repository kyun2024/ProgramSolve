#include <iostream>
#include <string>

using namespace std;

string reversed(string s){
    string res="";
    for(auto i=s.rbegin();i!=s.rend();i++){
        res += *i;
    }
    return res;
}

int a[1011];
int main(){
    int i,n;
    string s;
    cin >> s;
    s = reversed(s);
    for(i=0;i<s.length();i++){
        a[i]+=s[i]-'0';
        if(a[i]>1){
            a[i+1]+=1;
            a[i]-=2;
        }
        a[i+4]+=s[i]-'0';
    }
    for(;i<=1010;i++){
        if(a[i]>1){
            a[i+1]+=1;
            a[i]-=2;
        }
    }
    for(i=1011;a[i]==0&&i>=0;i--);
    for(;i>=0;i--){
        cout << a[i];
    }
    cout << endl;
    return 0;
}
