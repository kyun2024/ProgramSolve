#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n;
    while(t--){
        cin >> n;
        cout << n << " is ";
        n = abs(n);
        cout << (n%2==0?"even":"odd") << endl;
    }
    return 0;
}