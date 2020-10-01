#include <iostream>
#include <algorithm>

using namespace std;

int a[4];

int main(){
    for(auto& x : a){
        cin >> x;
    }
    sort(a,a+4);
    cout << abs(a[3]+a[0]-a[2]-a[1]) << endl;
    return 0;
}