#include <iostream>

using namespace std;

int m[4][100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    m[1][1]=1;
    m[2][2]=1;
    m[1][3]=1;
    m[2][3]=1;
    m[3][3]=1;
    int i;
    for(i=4;i<=100000;i++){
        m[1][i]=(m[2][i-1]+m[3][i-1])%1000000009;
        m[2][i]=(m[1][i-2]+m[3][i-2])%1000000009;
        m[3][i]=(m[1][i-3]+m[2][i-3])%1000000009;
    }
    int T;
    cin >> T;
    while(T--){
        cin >> i;
        cout << (((m[1][i]+m[2][i])%1000000009)+m[3][i])%1000000009 << '\n';
    }
}