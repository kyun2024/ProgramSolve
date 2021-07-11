#include <iostream>
#include <algorithm>

using namespace std;

pair<int,int> v[1000001];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    int i;
    for(i=1;i<=n;i++){
        cin >> v[i].first >> v[i].second;
    }
    sort(v+1,v+n+1,[](const pair<int,int>& i,const pair<int,int>& j){
        return i.first<j.first;
    });
    int res=0;
    int s=v[1].first,e=v[1].second;
    for(i=2;i<=n;i++){
        if(e<v[i].first){
            res += e-s;
            s = v[i].first;
            e = v[i].second;
        }
        else{
            s = min(s,v[i].first);
            e = max(e,v[i].second); 
        }
    }
    res += e-s;
    cout << res << endl;
    return 0;
}