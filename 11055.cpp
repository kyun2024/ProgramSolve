#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int i,j,m;
    int n{};
    vector<int> v,a;
    cin >> n;
    v.resize(n,0);
    a.resize(n,0);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    a[0]=v[0];
    for(i=1;i<n;i++){
        m = 0;
        for(j=0;j<i;j++){
            if(v[j]<v[i] && m<a[j]){
                m = a[j];
            }
        }
        a[i] = m + v[i];
    }
    cout << *max_element(a.begin(),a.end()) << endl;
    return 0;
}