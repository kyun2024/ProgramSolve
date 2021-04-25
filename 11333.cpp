#include <iostream>

using namespace std;

unsigned long long memo[3334];

void pre(){
    memo[1]=3;
    memo[0]=1;
    int i,j;
    for(i=2;i<=3333;i++){
        memo[i]=3*memo[i-1];
        for(j=0;j<i-1;j++){
            memo[i] = (memo[i]+2*(i-j)*memo[j])%1000000007;
        }
    }
}

void proc1(){
    int n;
    cin >> n;
    if(n%3!=0){
        cout << 0 << endl;
    }
    else cout << memo[n/3] << endl;
}

int main(){
    pre();
    int T;
    cin >> T;
    while(T--){
        proc1();
    }
}