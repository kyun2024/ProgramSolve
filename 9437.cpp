#include <iostream>

using namespace std;

int main(){
    int n,k;
    while(1){
        cin >> n;
        if(!n)break;
        cin >> k;
        if(k<=n/2 && k%2==0){
            cout << k-1 << " " << n-k+1 << " " << n-k+2 << endl;
        }
        else if(k<=n/2 && k%2==1){
            cout << k+1 << " " << n-k << " " << n-k+1 << endl;
        }
        else if(k>n/2 && k%2==1){
            cout << n-k << " " << n-k+1 << " " << k+1 << endl;
        }
        else if(k>n/2 && k%2==0){
            cout << n-k+1 << " " << n-k+2 << " " << k-1 << endl;
        }
    }
    return 0;
}