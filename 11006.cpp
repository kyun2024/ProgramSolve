#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    int n,m;
    while(T--){
        cin >> n >> m;
        cout << 2*m-n << " " << n-m << endl;
    }
    return 0;
}