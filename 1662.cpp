#include <iostream>
#include <string>

using namespace std;

int s[51];

int main(){
    string str;
    int t=0,i,p_v;
    cin >> str;
    for(i=str.length()-1;i>=0;i--){
        if(str[i]==')'){
            t++;
            s[t]=0;
        }
        else if(str[i]=='('){
            //routine
            p_v = s[t];
            t--;
        } 
        else{
            //number
            if(str[i+1]=='('){
                s[t] += (str[i]-'0')*p_v;
            }
            else s[t]++;
        }
    }
    cout << s[0] << endl;
}