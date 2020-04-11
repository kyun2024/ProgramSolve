#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int n,i;
    cin >> n;
    v.resize(n,0);
    for(auto& x: v){
        cin >> x;
    }
    sort(v.begin(),v.end(),greater<int>());
    for(i=0;i<n;i++){
        if(v[i]<i){
            cout << i << endl;
            break;
        }
    }
    if(i==n){
        cout << n << endl;
    }
    return 0;
}