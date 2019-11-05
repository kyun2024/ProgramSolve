#include <iostream>
#include <string>
#include <vector>
#include <array>

using namespace std;

int main(){
    vector<string> v;
    array<bool,26> ch;
    int n;
    int i,j,res=0;
    cin >> n;
    v.resize(n);
    cin.get();
    for(i=0;i<n;i++){
        getline(cin,v[i]);
    }
    for(const auto& str : v){
        bool c = true;
        ch.fill(false);
        for(i=0;i<str.length();i++){
            if(ch[str[i]-'a'] && str[i-1]!=str[i]){
                //cout << str[i] << " " << str[i-1];
                c=false;
                break;
            }
            ch[str[i]-'a']=true;
        }
        if(c)res+=1;
    }
    cout << res << endl;
    return 0;
}