#include <iostream>
#include <vector>

using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v;
    int n,i,j,min_val,idx;
    cin >> n;
    v.resize(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    for(i=0;i<n;i++){
        min_val=v[i];
        idx = i;
        for(j=i+1;j<n;j++){
            if(min_val>v[j]){
                min_val = v[j];
                idx = j;
            }
        }
        swap(v[i],v[idx]);
    }
    for(i=0;i<n;i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}