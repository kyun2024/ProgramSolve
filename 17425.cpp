#include <iostream>

using namespace std;

long long memo[1000001];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int i,j,n;
    for(i=1;i<=1000000;i++){
        for(j=i;j<=1000000;j+=i){
            memo[j]+=i;
        }
    }
    for(i=1;i<=1000000;i++){
        memo[i]+=memo[i-1];
    }
    
    cin >> n;
    while(n--){
        cin >> i;
        cout << memo[i] << '\n';
    }
    
    return 0;
}