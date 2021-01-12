#include <iostream>

using namespace std;

int main(){
    int n,k,c=0,i;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        if(n%i==0){
            c++;
            if(c==k){
                cout << i << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}