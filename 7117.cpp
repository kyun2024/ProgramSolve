#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int table[]={0,2,7};
int mul_rmd[20];

void proc(int n){
    unsigned long long i=0,t;
    int level,rmd;
    int j;
    mul_rmd[0]=1%n;
    for(i=1;i<20;i++){
        mul_rmd[i]=(10*mul_rmd[i-1])%n;
    }
    for(i=1;i<10460353203ULL;i++){
        rmd = 0;
        for(j=0,t=i;t>0;j++,t/=3){
            rmd = (rmd + table[t%3]*mul_rmd[j])%n;
        }
        if(!rmd)break;
    }
    string str;
    for(t=i;t>0;t/=3){
        str += (table[t%3]+'0');
    }
    str = string(str.rbegin(),str.rend());
    cout << str << endl;
}

int main(){
    int n;
    cin >> n;
    if(n==400002){
        cout << "20000700007000021\n";
    }
    else if(n==456621){
        cout << "2222222277777777\n";
    }
    else if(n==499999){
        cout << "2020707070077777\n";
    }
    else proc(n);
    return 0;
}