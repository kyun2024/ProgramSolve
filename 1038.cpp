#include <iostream>

using namespace std;

int combination(int n,int r){
    int res=1;
    int i;
    for(i=1;i<=n;i++){
        res *= i;
    }
    for(i=1;i<=r;i++){
        res /= i;
    }
    for(i=1;i<=n-r;i++){
        res /= i;
    }
    return res;
}

int main(){
    int n,i=0,s=0,l=0,j;
    long long res=0;
    cin >> n;
    for(l=1,s=-1;l<=10;l++){
        if(n<=s+combination(10,l)){
            n = n - s;
            break;
        }
        s += combination(10,l);
    }
    if(l>10){
        cout << -1 << endl;
        return 0;
    }
    for(i=l-1;i>=0;i--){
        s=0;
        for(j=i;j<=9;j++){
            if(n<=s+combination(j,i)){
                n = n - s;
                res = 10*res + j;
                break;
            }
            s += combination(j,i);
        }
    }
    cout << res << endl;
    return 0;
}