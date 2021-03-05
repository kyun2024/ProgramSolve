#include <iostream>
#include <string>

using namespace std;

int uglies=0;
string str;

void rec(int idx,long long tot,int sign,long long s){
    if(idx==str.length()){
        tot += sign*s;
        //tot = ((tot<0)?(-tot):(tot));
        if(tot%2==0 || tot%3==0 || tot%5==0 || tot%7==0){
            uglies++;
        }
        return;
    }
    rec(idx+1,tot+sign*s,1,str[idx]-'0');
    rec(idx+1,tot+sign*s,-1,str[idx]-'0');
    rec(idx+1,tot,sign,10*s+(str[idx]-'0'));
}

int main(){
    int test_case;
    cin >> test_case;
    for(int i=1;i<=test_case;i++){
        cin >> str;
        uglies=0;
        rec(1,0,1,str[0]-'0');
        cout << "Case #" << i << ": " << uglies << '\n';
    }
}