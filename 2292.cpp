#include <iostream>
using namespace std;

auto main()->int{
    int n,s,i;
    cin >> n;
    s = 1;
    for(i=1;s<n;++i){
        s+=i*6;
    }
    cout << i << endl;
    return 0;
}