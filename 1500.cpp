#include <iostream>

using namespace std;

int main(){
    using ll=long long;
    ll s,k,p,r,res=1;
    int i;
    cin >> s >> k;
    p=s/k;
    r=s%k;
    for(i=0;i<r;i++){
        res *= (p+1);
    }
    for(;i<k;i++){
        res *= p;
    }
    cout << res << endl;
}