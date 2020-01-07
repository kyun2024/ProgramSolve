#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bs(vector<int>& v,int n){
    int s,e,m;
    s=0;
    e=v.size()-1;
    while(s<=e){
        m=(s+e)/2;
        if(n < v[m]){
            e = m-1;
        }
        else if(v[m]<n){
            s = m+1;
        }
        else{
            return m;
        }
    }
    return -1;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    std::ios_base::sync_with_stdio(false);

    int n,t;
    vector<int> v;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;
        cout << (bs(v,t) >= 0) << '\n';
    }
    return 0;
}