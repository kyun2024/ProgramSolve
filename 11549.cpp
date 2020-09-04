#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[5];
    int r;
    cin >> r;
    for(int i=0;i<5;i++){
        cin >> a[i];
    }
    cout << count(a,a+5,r) << endl;
    return 0;
}