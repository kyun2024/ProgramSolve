#include <iostream>

using namespace std;

int memo[1000001];

int main(){
    int a,b;
    int T;
    int i,t;

    memo[0]=1;
    for(i=1;i<=1000000;i++){
        t = i;
        while(t>0){
            memo[i] += t%10 == 0;
            t/=10;
        }
        memo[i] += memo[i-1];
    }
    cin >> T;
    while(T--){
        cin >> a >> b;
        if(a!=0){
            cout << memo[b]-memo[a-1] << endl;
        }
        else{
            cout << memo[b] << endl;
        }
    }
    return 0;
}