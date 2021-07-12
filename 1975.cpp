#include <iostream>

using namespace std;

int m[1001];

int main(){
    int i,j,k;
    int T,n;

    cin.tie(0)->sync_with_stdio(false);

    for(i=1;i<=1000;i++){
        for(j=2;j<=i;j++){
            for(k=j;i%k==0;k*=j){
                m[i]++;
            }
        }
    }

    cin >> T;
    while(T--){
        cin >> n;
        cout << m[n] << '\n';
    }
    return 0;
}