#include <iostream>

using namespace std;

unsigned long long fibo[117];

int main(){
    int i;
    fibo[1]=fibo[2]=fibo[3]=1;
    for(i=4;i<=116;i++){
        fibo[i]=fibo[i-1]+fibo[i-3];
    }
    cin >> i;
    cout << fibo[i] << endl;
    return 0;
}