#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    int a[26];
    fill_n(a,26,-1);
    getline(cin,s);
    for(int i=0;i<s.length();i++){
        if(a[s[i]-'a']==-1){
            a[s[i]-'a']=i;
        }
    }
    for(int i=0;i<26;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}