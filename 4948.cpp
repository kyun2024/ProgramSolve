#include <iostream>

using namespace std;

int main(){
    int n,i,j,s;
    while(true){
        cin >> n;
        if(n==0)break;
        s = 0;
        for(i=n+1;i<=2*n;i++){
            s++;
            for(j=2;j*j<=i;j++){
                if(i%j==0){
                    s--;
                    break;
                }
            }
        }
        cout << s << endl;
    }
}