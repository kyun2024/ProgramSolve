#include <iostream>

using namespace std;

int main(){
    int n,l,d;
    int i,j;
    int t=0;
    cin >> n >> l >> d;
    for(i=1;i<=n;i++){
        while(t<i*l+(i-1)*5){
            t += d;
        }
        if(i==n || t<i*(l+5)){
            cout << t << endl;
            break;
        }
    }
}