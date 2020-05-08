#include <iostream>

using namespace std;

int main(){
    int x,l,r;
    cin >> x >> l >> r;
    if(l<=x && x<=r){
        cout << x << endl;
    }
    else if(x<=l){
        cout << l << endl;
    }
    else cout << r << endl;
    return 0;
}