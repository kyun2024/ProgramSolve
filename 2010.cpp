#include <iostream>

using namespace std;

int main(){
    int n,s{},t;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        s += t;
    }
    cout << s - n + 1 << endl;
    return 0;
}