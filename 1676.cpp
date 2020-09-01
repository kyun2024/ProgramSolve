#include <iostream>

using namespace std;

//i/5 + i/25 + i/125 + i/625 + i/3125 + i/15625 + i/78125 + i/390625 + i/1953125

int main(){
    long long n,r=0,i;
    cin >> n;
    for(i=5;i<=1LL<<60;i*=5){
        r += n/i;
    }
    cout << r << endl;
    return 0;
}