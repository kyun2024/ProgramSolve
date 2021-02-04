#include <iostream>

using namespace std;

int m[1516][15];

// 1000000007

int main(){
    int i,j;
    m[1][1] = m[1][5] = 1;
    for(i=2;i<=1515;i++){
        for(j=0;j<15;j++){
            if(m[i-1][j]!=0){
                m[i][(10*j+1)%15]=(m[i][(10*j+1)%15]+m[i-1][j])%1000000007;
                m[i][(10*j+5)%15]=(m[i][(10*j+5)%15]+m[i-1][j])%1000000007;
            }
        }
    }
    int n;
    cin >> n;
    cout << m[n][0] << endl;
    return 0;
}