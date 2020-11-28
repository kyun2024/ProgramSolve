#include <iostream>

using namespace std;

int m[191230];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    m[0]=m[1]=1;
    int i;
    for(i=2;i<=191229;i++){
        m[i]=(m[i-1]+m[i-2])%1000000007;
    }
    int T;
    cin >> T;
    while(T--){
        cin >> i;
        cout << m[i] << '\n';
    }
    return 0;
}