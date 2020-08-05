#include <iostream>

using namespace std;

int m[2][3];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T,n,i;
    int a,b,c,r;
    
    for(T=1;;T++){
        cin >> n;
        if(n==0)break;
        cin >> a >> b >> c;
        m[1][0] = 1000;
        m[1][1] = b;
        m[1][2] = b+c;
        for(i=2;i<=n;i++){
            cin >> a >> b >> c;
            m[i%2][0] = min(m[(i+1)%2][0],m[(i+1)%2][1])+a;
            m[i%2][1] = min(min(m[(i+1)%2][0],m[(i+1)%2][1]),min(m[(i+1)%2][2],m[i%2][0]))+b;
            m[i%2][2] = min(min(m[(i+1)%2][1],m[(i+1)%2][2]),m[i%2][1])+c;
        }
        cout << T << ". " << m[n%2][1] << endl;
    }
}