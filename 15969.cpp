#include <iostream>
#include <algorithm>

using namespace std;

int m[1000];

int main(){
    int n,i;
    cin >> n;
    for(i=0;i<n;i++)cin >> m[i];
    cout << *max_element(m,m+n) - *min_element(m,m+n) << endl;
    return 0;
}