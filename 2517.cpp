#include <iostream>
#include <algorithm>

using namespace std;

int seg_a[500001];
pair<int,int> dt_a[500001];
int p_a[500001];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n,i,x;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> dt_a[i].first;
        dt_a[i].second = i;
    }
    sort(dt_a+1,dt_a+n+2,[](pair<int,int>& i,pair<int,int>& j){
        return i.first>j.first;
    });
    for(i=1;i<=n;i++){
        x = dt_a[i].second;
        while(x>0){
            p_a[dt_a[i].second] += seg_a[x];
            x -= (x & -x);
        }
        x = dt_a[i].second;
        while(x<=n){
            seg_a[x]++;
            x += (x&-x);
        }
    }
    for(i=1;i<=n;i++)cout << p_a[i]+1 << '\n';
    return 0;
}
