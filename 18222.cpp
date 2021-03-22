#include <iostream>

using namespace std;

unsigned long long b2[64];

int main(){   
    int i;
    b2[0]=1;
    for(i=1;i<=60;i++){
        b2[i]=2*b2[i-1];
    }

    unsigned long long n;
    bool invert=false;
    cin >> n;
    for(i=60;i>=0;i--){
        if(b2[i]<n){
            invert=!invert;
            n -= b2[i];
        }
    }
    cout << invert << endl;
    return 0;
}