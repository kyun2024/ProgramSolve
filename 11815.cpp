#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    long long n;
    cin >> t;
    while(t--){
        cin >> n;
        long long q = sqrtl(n);
        cout << (q*q==n) << " ";
    }
    cout << endl;
    return 0;
}
