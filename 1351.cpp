#include <iostream>

using namespace std;

int dp[10000001];
long long n,p,q;

long long a(long long t){
    if(t==0)return 1;
    if(t<=10000000 && dp[t]!=0)return dp[t];
    //cout << t << endl;
    if(t<=10000000 && dp[t]==0)return dp[t]=a(t/p)+a(t/q);
    else return a(t/p)+a(t/q);
}

int main(){
    cin >> n >> p >> q;
    cout << a(n) << endl;
    return 0;
}