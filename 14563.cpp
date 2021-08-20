#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int n,s,i;
    while(T--){
        s=0;
        cin >> n;
        for(i=1;i<n;i++){
            if(n%i==0)s+=i;
        }
        if(s<n){
            cout << "Deficient\n";
        }
        else if(s>n){
            cout << "Abundant\n";
        }
        else{
            cout << "Perfect\n";
        }
    }
    return 0;
}