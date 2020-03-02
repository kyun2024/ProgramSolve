#include <iostream>

using namespace std;

int dp[100001];

int q(int n){
    if(n==1)return n;
    else if(n<=100000 && dp[n]!=0){
        return dp[n];
    }
    else if(n%2==0){
        if(n<=100000){
            return dp[n]=max(n,q(n/2));
        }
        else{
            return max(n,q(n/2));
        }
    }
    else
    {
        if(n<=100000){
            return dp[n]=max(n,q(3*n+1));
        }
        else{
            return max(n,q(3*n+1));
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t,a;
    cin >> t;
    while(t--){
        cin >> a;
        cout << q(a) << '\n'; 
    }
    return 0;
}