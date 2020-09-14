#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int n,i;
    cin >> n;
    for(i=1;i<=n;i++){
        cout << 1;
    }
    for(i=1;i<n;i++){
        cout << 0;
    }
    cout << endl;
    return 0;
}