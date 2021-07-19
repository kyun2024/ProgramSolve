#include <iostream>

using namespace std;

int v[3001];
long long sv[3001];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int i,j,k;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
        sv[i]=v[i]+sv[i-1];
    }
    long long res = 1e15;
    int res_k = 0;
    for(k=1;k<=n/2;k++){
        for(i=2*k;i<=n;i++){
            for(j=k;j<=i-k;j++){
                if(res>=abs(sv[i]-sv[i-k]-sv[j]+sv[j-k])){
                    res = abs(sv[i]-sv[i-k]-sv[j]+sv[j-k]);
                    res_k = k;
                }
            }
        }
    }
    cout << res_k << endl << res << endl;
    return 0;
}