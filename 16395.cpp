#include <iostream>

using namespace std;

unsigned long long psc[31][31];

int main(){
    int i,j;
    psc[0][0]=1;
    for(i=1;i<=30;i++){
        psc[i][0]=1;
        for(j=1;j<=i;j++){
            psc[i][j]=psc[i-1][j-1]+psc[i-1][j];
        }
    }
    int n,k;
    cin >> n >> k;
    cout << psc[n-1][k-1] << endl;
    return 0;
}