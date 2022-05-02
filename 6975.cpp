#include <iostream>

using namespace std;

int main(){
    int t,n,c,i;
    cin >> t;
    while(t--){
        cin >> n;
        c = 0;
        for(i=1;i<n;i++){
            if(n%i==0)c+=i;
        }
        cout << n << " is ";
        if(c<n){
            cout << "a deficient ";
        }
        else if(c==n){
            cout << "a perfect ";
        }
        else cout << "an abundant ";
        cout << "number.\n\n";
    }
    return 0;
}
