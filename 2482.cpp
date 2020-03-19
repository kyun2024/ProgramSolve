#include <iostream>

using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    if(k==1)cout << n << endl;
    else if(n<2*k)cout << 0 << endl;
    else cout << 2+(n-2*k)*(2*k-1) << endl;
    return 0;
}