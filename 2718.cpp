#include <iostream>

using namespace std;

int m4[100];

int main(){
    ios_base::sync_with_stdio(false);
    
    int i,j,T;
    m4[0]=1;
    m4[1]=1;
    for(i=2;i<=24;i++){
        m4[i]=m4[i-1]+3*m4[i-2];
        for(j=2;j<=i;j++){
            m4[i] += (j%2==0)*m4[i-j] + (j>2)*2*m4[i-j];
        }
    }
    cin >> T;
    while(T--){
        cin >> i;
        cout << m4[i] << '\n';
    }
}