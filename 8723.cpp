#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int s[3]={0,};
    for(auto& x:s){
        cin >> x;
    }
    sort(s,s+3);
    if(s[0]*s[0]+s[1]*s[1]==s[2]*s[2]){
        cout << 1 << endl;
    }
    else if(s[0]==s[1] && s[1]==s[2]){
        cout << 2 << endl;
    }
    else cout << 0 << endl;
    return 0;
}