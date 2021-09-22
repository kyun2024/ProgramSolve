#include <iostream>
#include <vector>

using namespace std;

int limit_c = 987654321;
vector<int> v;
int memo[100001];

int dp(int n){
    if(memo[n])return memo[n];
    int res=100000;
    for(int i=0;i<v.size() && n-v[i]>0;i++){
        res = min(res,1+dp(n-v[i]));
    }
    return memo[n] = res;
}

int main(){
    int i,f;
    //init
    i = 2;f = 1;
    while(f<=100000){
        v.push_back(f);
        memo[f]=1;
        f *= i++;
    }

    int n;
    cin >> n;
    cout << dp(n) << endl;
    return 0;
}