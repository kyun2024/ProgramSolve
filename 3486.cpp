#include <iostream>

using namespace std;

int r(int n){
    int res=0;
    while(n){
        res = 10*res+(n%10);   
        n/=10;
    }
    return res;
}

int main(){
    int t;
    int a,b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        cout << r(r(a)+r(b)) << endl;
    }
    return 0;
}