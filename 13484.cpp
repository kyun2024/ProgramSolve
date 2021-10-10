#include <iostream>

using namespace std;

int main(){
    int n,a,res;
    cin >> a;
    cin >> n;
    res = a*(n+1);
    while(n--){
        cin >> a;
        res -= a;
    }
    cout << res << endl;
    return 0;
}