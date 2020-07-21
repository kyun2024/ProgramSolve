#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int a[10];
    int t;
    int i;
    cin >> t;
    while(t--){
        for(i=0;i<10;i++)cin >> a[i];
        sort(a,a+10,greater<int>());
        cout << a[2] << endl;
    }
    return 0;
}