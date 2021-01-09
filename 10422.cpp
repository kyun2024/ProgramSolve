#include <iostream>

using namespace std;

unsigned long long m[2501];

int main(){
    m[0]=1;
    int i,j;
    for(i=1;i<=2500;i++){
        for(j=0;j<i;j++){
            m[i]=(m[i]+m[j]*m[i-j-1])%1000000007;
        }
    }
    cin >> i;
    while(i--){
        cin >> j;
        if(j%2==1){
            cout << 0 << '\n';
        }
        else{
            cout << m[j/2] << '\n';
        }
    }
    return 0;
}