#include <iostream>
#include <algorithm>
#include <array>
#include <numeric>

using namespace std;

int main(){
    int b[2];
    array<int,4> a;
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> b[0] >> b[1];
    cout << accumulate(a.begin(),a.end(),0)-*min_element(a.begin(),a.end())+max(b[0],b[1]) << endl;
}