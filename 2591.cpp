#include <iostream>
#include <string>

using namespace std;

int memo[40];

int main(){
    string str;
    int a,i;
    cin >> str;
    memo[0]=1;
    for(i=1;i<str.length();i++){
        a = 10*(str[i-1]-'0')+(str[i]-'0');
        if(str[i-1]!='0' && a<=34){
            if(i==1){
                memo[i] += 1;
            }
            else memo[i] += memo[i-2];
        }
        if(str[i]!='0'){
            memo[i] += memo[i-1];
        }
    }
    cout << memo[str.length()-1] << endl;
    return 0;
}
