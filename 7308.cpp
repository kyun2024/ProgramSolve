#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main(){
    int T;
    long long a,b,t,sgn,esgn;
    string expr;
    cin >> T;
    cin.get();
    while(T--){
        getline(cin,expr);
        a=b=t=0;
        sgn=esgn=1;
        for(char ch : expr){
            if('0'<= ch && ch <= '9'){
                t = 10*t+(ch-'0');
            }
            if(ch=='x'){
                if(t==0)t=1;
                a += esgn*sgn*t;
                t = 0;
            }
            if(ch=='+'){
                b += esgn*sgn*t;
                sgn = 1;
                t = 0;
            }
            if(ch=='-'){
                b += esgn*sgn*t;
                sgn = -1;
                t = 0;
            }
            if(ch=='='){
                b += esgn*sgn*t;
                sgn=1;
                esgn=-1;
                t=0;
            }
        }
        b += esgn*sgn*t;
        if(a==0){
            if(b!=0){
                cout << "IMPOSSIBLE" << '\n';
            }
            else{
                cout << "IDENTITY" << '\n';
            }
        }
        else cout << (long long)(floor((double)(-b)/a)) << '\n';
    }
}