#include <iostream>
#include <iomanip>

using namespace std;

constexpr int mod_n = 10007;
int m[1000001];
bool check[1000001];

int dfs(int n){
    if(n<=4)return n;
    if(check[n]){
        return m[n];
    }
    check[n]=true;
    return m[n]=(3*dfs(n-3))%mod_n;
}

int main(){
    int n;
    cin >> n;
    cout << dfs(n) << endl;
    return 0;
}