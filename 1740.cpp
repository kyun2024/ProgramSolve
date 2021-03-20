#include <iostream>

using namespace std;

unsigned long long thr[64];

int main(){
    unsigned long long n,i;
    cin >> n;
    thr[0]=1;
    for(i=1;i<64;i++){
        thr[i]=3*thr[i-1];
    }
    unsigned long long r=0;
    for(i=0;n>0;i++){
        if(n%2)r += thr[i];
        n/=2;
    }
    cout << r << endl;
    return 0;
}