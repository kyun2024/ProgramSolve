#include <iostream>

using namespace std;

int main(){
    int a[5],avg{};
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    avg += (a[0]>40)? a[0] : 40;
    avg += (a[1]>40)? a[1] : 40;
    avg += (a[2]>40)? a[2] : 40;
    avg += (a[3]>40)? a[3] : 40;
    avg += (a[4]>40)? a[4] : 40;
    avg /= 5;
    cout << avg << endl;
    return 0;
}