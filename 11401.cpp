#include <iostream>
#include <map>

using namespace std;

map<int,int> modulo_inv;

constexpr long long mod_n = 1'000'000'007;

int solve(int c){
    if(modulo_inv.find(c)!=modulo_inv.end()){
        return modulo_inv[c];
    }
    long long term_a,term_b;
    term_a = solve(c/2);
    term_b = solve((c+1)/2);
    modulo_inv[c]=(term_a*term_b)%mod_n;
    return modulo_inv[c];
}

int fact(int n){
    long long x=1;
    for(int i=n;i>=1;i--){
        x = (x*i)%mod_n;
    }
    return x;
}

int main(){
    int n,k;
    cin >> n >> k;
    if(n<k){
        cout << 0 << endl;
        return 0;
    }
    modulo_inv[1]=fact(k);
    long long term_a,term_b,i;
    term_a=1;
    for(i=n;i>(n-k);i--){
        term_a = (term_a*i)%mod_n;
    }
    term_b = solve(mod_n-2);
    cout << term_a << " " << term_b << endl;
    cout << (term_a*term_b)%mod_n << endl;
    return 0;
}