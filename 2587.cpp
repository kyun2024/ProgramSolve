#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int a[5];

int main(){
    int i;
    for(i=0;i<5;i++)cin >> a[i];
    sort(a,a+5);
    int r=accumulate(a,a+5,0)/5;
    cout << r << endl << a[2] << endl;
    return 0;
}