#include <iostream>

long long m[3][1000001],s[1000001];

using namespace std;

int main(){
    m[0][0]=m[1][0]=m[0][1]=m[2][1]=1;
    int i;
    s[0]=1;
    s[1]=2;
    for(i=2;i<=1000000;i++){
        m[0][i]=s[i-1]%1000000007;
        m[1][i]=(m[2][i-1]+s[i-2])%1000000007;
        m[2][i]=(m[2][i-1]+s[i-1])%1000000007;
        s[i] = (m[0][i]+m[1][i]+m[2][i])%1000000007;
    }
    cin >> i;
    cout << s[i] << endl;
    return 0;
}