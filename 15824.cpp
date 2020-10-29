#include <iostream>
#include <algorithm>

using namespace std;

long long exp2a[300000];
long long d[300000];

constexpr int div_n = 1000000007;

int main(){
    int i,x;
    i=0;x=1;
    while(i<300000){
        exp2a[i]=(x+div_n-1)%div_n;
        i++;
        x = (2*x)%div_n;
    }
    long long res=0,t;
    int n;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> d[i];
    }
    sort(d,d+n);
    for(i=0;i<n-1;i++){
        t = (d[i]*exp2a[n-i-1])%div_n;
        t = (div_n-t)%div_n;
        res = (res+t)%div_n;
        //cout << t << " " << t-div_n << " " << exp2a[n-i-1] <<endl;
    }
    for(i=n-1;i>0;i--){
        t = (d[i]*exp2a[i])%div_n;
        res = (res+t)%div_n;
        //cout << t << " " << t-div_n << endl;
    }
    cout << res << endl;
    return 0;
}