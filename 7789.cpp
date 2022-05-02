#include <iostream>

using namespace std;

bool isprime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return 1;
}

int main(){
    int n,k;
    cin >> n >> k;
    cout << (isprime(n)&&isprime(1e6*k+n)?"Yes":"No") << endl;
    return 0;
}
