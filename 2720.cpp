#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        cout << n/25 << " ";
        n = n - (n/25)*25;
        cout << n/10 << " ";
        n = n - (n/10)*10;
        cout << n/5 << " ";
        n = n - (n/5)*5;
        cout << n << endl;
    }
    return 0;
}