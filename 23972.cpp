#include <iostream>

using namespace std;

int main(){
    long long n,k;
    cin >> k >> n;
    if(n==1)cout << -1;
    else cout << (n*k+n-2)/(n-1) << endl;
    return 0;
}