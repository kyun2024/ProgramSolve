#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[5];
    int n,i;
    cin >> n;
    for(i=0;i<5;i++){
        cin >> a[i];
    }
    cout << count(a,a+5,n) << endl;
    return 0;
}