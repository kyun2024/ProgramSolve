#include <iostream>

using namespace std;

int main(){
    int n,i,s;
    while(true){
        cin >> n;
        if(n==-1)break;
        s=1;
        for(i=2;i<n;i++){
            if(n%i==0){
                s+=i;
            }
        }
        if(n==s){
            cout << n << " = " << 1;
            for(i=2;i<n;i++){
                if(n%i==0){
                    cout << " + " << i;
                }
            }
            cout << endl;
        }
        else{
            cout << n << " is NOT perfect." << endl;
        }
    }
    return 0;
}