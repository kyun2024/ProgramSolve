#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<long long> m;
vector<long long> v;

int main(){
    int n;
    int i,j;
    long long res=0,key;
    cin >> n;
    v.resize(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            m.push_back(v[i]+v[j]);
        }
    }
    sort(m.begin(),m.end());
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            key = v[j]-v[i];
            if(binary_search(m.begin(),m.end(),key)){
                res = max(res,v[j]);
            }
        }
    }
    cout << res << endl;
    return 0;
}