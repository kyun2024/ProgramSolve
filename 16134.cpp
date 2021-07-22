#include <iostream>

using namespace std;

constexpr int mod_n = 1000000007;

long long inv_bit_v[32];
long long inv_p(int n){
    inv_bit_v[0]=n;
    for(int i=1;i<32;i++){
        inv_bit_v[i]=(inv_bit_v[i-1]*inv_bit_v[i-1])%mod_n;
    }
    int t = mod_n-2;
    long long res=1; 
    for(int i=0;t>0;i++){
        if(t&1)res = (res * inv_bit_v[i])%mod_n;
        t>>=1;
    }
    return res;
}

int main(){
    long long n,r;
    cin >> n >> r;
    if(r==0 || r==n){
        cout << 1 << endl;
        return 0;
    }
    long long res=1;
    long long i;
    for(i=1;i<=r;i++){
        res = (res * (n-i+1))%mod_n;
    }
    for(i=1;i<=r;i++){
        res = (res * inv_p(i))%mod_n;
    }
    cout << res << endl;
    return 0;
}