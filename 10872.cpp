#include <iostream>

using namespace std;

int main(){
    int n;
    int res=1;
    cin >> n;
    for(int i=1;i<=n;i++){
        res *= i;
    }
    cout << res << endl;
    return 0;
}