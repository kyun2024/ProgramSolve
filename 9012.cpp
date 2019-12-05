#include <iostream>
#include <string>

using namespace std;

bool isVPS(string s){
    int lv=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            lv+=1;
        }
        else if (s[i]==')')
        {
            lv-=1;
        }
        if(lv<0)return false;
    }
    if(lv!=0)return false;
    return true;
}

int main(){
    int n;
    string in_buf;
    cin >> n;
    cin.get();
    while(--n >= 0){
        cin >> in_buf;
        cout << (isVPS(in_buf)?"YES":"NO") << endl;
    }
}