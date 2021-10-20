#include <iostream>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int T,n;
    cin >> T;
    while(T--){
        cin >> n;
        cout << ((n & -n) == n) << '\n';
    }
    return 0;
}