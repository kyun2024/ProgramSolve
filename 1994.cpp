#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int a[2001];
map<int,vector<pair<int,int>>> v;

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    int res=1,c=1;
    for(i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            res = max(res,++c);
        }
        else{
            c = 1;
        }
    }
    n = unique(a+1,a+n+1)-a-1;
    for(i=2;i<=n;i++){
        if(v.find(a[i])!=v.end()){
            for(auto p : v[a[i]]){
                res = max(res,p.first+1);
                v[a[i]+p.second].push_back(make_pair(p.first+1,p.second));
            }
            v[a[i]]=vector<pair<int,int>>();
        }
        for(j=1;j<i;j++){
            res = max(res,2);
            v[2*a[i]-a[j]].push_back(make_pair(2,a[i]-a[j]));
        }
    }
    cout << res << endl;
    return 0;
}