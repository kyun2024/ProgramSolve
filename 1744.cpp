#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int sum=0;
    int n,i,j,k;
    cin >> n;
    v.resize(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end(),greater<int>());
    for(i=0;i<n-1;i+=2){
        if(v[i]*v[i+1]>v[i]+v[i+1] && v[i]>0 && v[i+1]>=0){
            sum += v[i]*v[i+1];
        }
        else break;
    }
    for(k=n-1;k>max(i,0);k-=2){
        if(v[k]*v[k-1]>v[k]+v[k-1]){
            sum += v[k]*v[k-1];
        }
        else break;
    }
    for(j=i;j<=k;j++){
        sum += v[j];
    }
    cout << sum << endl;
    return 0;
}