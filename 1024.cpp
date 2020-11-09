#include <iostream>

using namespace std;

int main(){
    int n,k;
    int i,j,m,s=0;
    cin >> n >> k;
    for(i=k;i<=100;i++){
        m = n/i;
        s = 0;
        if(m-(i/2)+(i%2==0)<0)break;
        for(j=m-(i/2)+(i%2==0);j<=m+(i/2);j++){
            s += j;
        }
        if(s==n){
            for(j=m-(i/2)+(i%2==0);j<=m+(i/2);j++){
                cout << j << " ";
            }
            cout << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}