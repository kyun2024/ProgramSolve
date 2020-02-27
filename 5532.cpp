#include <iostream>

using namespace std;

int main(){
    int n,a,b,l,k;
    cin >> n >> a >> b >> l >> k;
    cout << n-max((a+l-1)/l,(b+k-1)/k) << endl;
    return 0;
}