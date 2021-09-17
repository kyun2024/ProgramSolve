#include <iostream>

using namespace std;

int main(){
    int t;
    int n,c;
    cin >> t;
    while(t--){
        cin >> n >> c;
        cout << (n+c-1)/c << endl;
    }
    return 0;
}