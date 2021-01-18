#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int m,n,res=0;
    vector<int> v1,v2;
    cin >> m >> n;
    v1.resize(m);
    v2.resize(n);
    for(auto& x : v1){
        cin >> x;
    }
    for(auto& x : v2){
        cin >> x;
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int i1=0,i2=0;
    while(i1<m && i2<n){
        if(v1[i1]==v2[i2]){
            i1++;
            i2++;
        }
        else if(v1[i1]>v2[i2]){
            res++;
            i2++;
        }
        else{
            res++;
            i1++;
        }
    }
    cout << res + m + n - i1 - i2 << endl;
    return 0;
}