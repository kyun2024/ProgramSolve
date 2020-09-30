#include <iostream>

using namespace std;

long long memo[10001];

long long fastpow2(int n){
    if(0<=n && n<=10000){
        return memo[n];
    }
    //cout << n/2 << " " << n/2+n%2 << endl;
    return (fastpow2(n/2)*fastpow2(n/2+n%2))%1'000'000'007;
}

int main(){
    int t,n,i;
    memo[0]=1;
    for(i=1;i<=10000;i++){
        memo[i]=(2*memo[i-1])%1'000'000'007;
    }
    cin >> t;
    while(--t>=0){
        cin >> n;
        cout << fastpow2(max(0,n-2)) << endl;
    }
    return 0;
}