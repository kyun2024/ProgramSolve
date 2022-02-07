#include <iostream>

using namespace std;

long long m[31][31];

int main(){
    int i,j;
    for(j=0;j<=30;j++){
        m[0][j]=1;
    }
    for(i=1;i<=30;i++){
        m[i][0]=m[i-1][1];
        for(j=1;j<30;j++){
            m[i][j]=m[i][j-1]+m[i-1][j+1];
        }
        m[i][30]=m[i][j-1];
    }
    while(1){
        cin >> i;
        if(!i)break;
        cout << m[i][0] << endl;
    }
    return 0;
}