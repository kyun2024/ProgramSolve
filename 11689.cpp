#include <iostream>

using namespace std;

bool is_prime(unsigned long long n){
    for(unsigned long long i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

unsigned long long solve(unsigned long long n){
    unsigned long long res = n;
    bool c=false;
    if(n==1)return 1;
    if(is_prime(res))return res-1;
    for(int i=2;i<=1000000;i++){
        if(n==1)break;
        c = n%i == 0;
        if(c)res = (res/i)*(i-1);
        while(n%i==0)n/=i;
        if(n!=1 && c && is_prime(n)){
            res = (res/n)*(n-1);
            n=1;
        }
    }
    return res;
}

int main(){
    unsigned long long n;
    cin >> n;
    cout << solve(n) << endl;
    return 0;
}