#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n;
    vector<int> v,a;
    cin >> n;
    v.resize(n);
    a.resize(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    a[0]=1;
    for(int i=1;i<n;i++){
        int m=0;
        for(int j=0;j<i;j++){
            if(m<a[j] && v[j]>v[i]){
                m = a[j];
            }
        }
        a[i]= m+1;
    }
    cout << *max_element(a.begin(),a.end()) << endl;
    return 0;
}