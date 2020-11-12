#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,int> m;

int solve(string n){
    if(n.length()==1)return 1;
    if(m.find(n)!=m.end()){
        return m[n];
    }
    m[n] = solve(n.substr(0,n.length()-1))+solve(n.substr(1,n.length()-1));
    if(n.substr(0,n.length()-1).compare(n.substr(1,n.length()-1))==0){
        m[n]/=2;
    }
    return m[n];
}

int main(){
    string n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}