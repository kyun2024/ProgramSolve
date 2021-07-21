#include <iostream>

using namespace std;

constexpr int mod_n = 1000000007;

long long memo[32];

long long inv_num(long long n){
    memo[0]=n;
    int i;
    for(i=1;i<32;i++){
        memo[i]=(memo[i-1]*memo[i-1])%mod_n;
    }
    long long res=1,t=mod_n-2;
    for(i=0;t>0;i++){
        if(t&1)res = (res * memo[i])%mod_n;
        t>>=1;
    }
    return res;
}

long long v_s[10001],v_n[10001];

int main(){
    int m;
    long long res=0;
    int i;
    cin >> m;
    for(i=1;i<=m;i++){
        cin >> v_n[i] >> v_s[i];
    }
    for(i=1;i<=m;i++){
        res = (res + v_s[i]*inv_num(v_n[i]))%mod_n;
    }
    cout << res << endl;
    return 0;
}