#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin >> n;
    v.resize(max(2,n),0);
    v[0] = 3;
    v[1] = 7;
    for(int i=2;i<n;i++){
        v[i] = (2*v[i-1] + v[i-2])%9901;
    }
    cout << v[n-1] << endl;
    return 0;
}