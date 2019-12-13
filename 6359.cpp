#include <iostream>
#include <array>

using namespace std;

int main(){
    array<int, 101> a;
    a.fill(0);
    int i,j;
    a[1] = 1;
    for(i=2;i<=100;i++){
        for(j=2;j<=i/2;j++){
            a[i] += i%j == 0;
        }
        a[i] = a[i]%2+a[i-1];
    }
    int t;
    cin >> t;
    for(i=0;i<t;i++){
        cin >> j;
        cout << a[j] << endl;
    }
    return 0;
}