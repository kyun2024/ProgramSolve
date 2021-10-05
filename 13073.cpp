#include <iostream>

using namespace std;

int main(){
    int t,n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << n*(n+1)/2 << " " << n*n << " " << n*n+n << endl;
    }
    return 0;
}