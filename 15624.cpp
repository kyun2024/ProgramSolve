#include <iostream>

using namespace std;

int m[1000001];

int main(){
    m[1]=1;
    int i;
    for(i=2;i<=1000000;i++){
        m[i]=(m[i-1]+m[i-2])%1000000007;
    }
    cin >> i;
    cout << m[i] << endl;
    return 0;
}