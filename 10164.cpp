#include <iostream>

using namespace std;

long long combination(long long n,long long c){
    long long res=1;
    if(n/2>=c)c=n-c;
    for(long long i=c+1;i<=n;i++){
        res *= i;
    }
    for(long long i=c+1;i<=n;i++){
        res /= i-c;
    }
    return res;
}

int main(){
    long long n,m,k,mr,mc;
    cin >> n >> m >> k;
    mr = (k-1)/m;
    mc = (k-1)%m;
    if(k==0){
        cout << combination(n+m-2,n-1) << endl;
    }
    else cout << combination(mr+mc,mr) * combination(n-1-mr+m-1-mc,n-1-mr) << endl;
    return 0;
}