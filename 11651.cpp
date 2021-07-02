#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int,int> v[100000];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    int i;
    for(i=0;i<n;i++)cin >> v[i].first >> v[i].second;
    sort(v,v+n,[](const pair<int,int>& i,const pair<int,int> &j){
        if(i.second==j.second){
            return i.first<j.first;
        }
        return i.second<j.second;
    });
    for(i=0;i<n;i++)cout << v[i].first << " " << v[i].second << '\n';
    return 0;
}