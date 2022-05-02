#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int m[100001];

int main(){
    int n,k,i,j;
    int res=0;
    vector<int> v;
    cin >> n >> k;
    for(i=2;i<=k;i++){
        for(j=2;j*j<=i;j++){
            if(i%j==0)break;
        }
        if(j*j>i)
        {
            v.push_back(i);
        }
    }
    queue<pair<int,int>> q;
    for(i=0;i<v.size();i++){
        q.push({v[i],i});
        m[v[i]]=1;
    }
    while(!q.empty())
    {
        pair<int,int> p = q.front();
        for(i=p.second;i<v.size();i++){
            if(p.first * v[i] <= 100000 && m[p.first * v[i]] == 0){
                m[p.first * v[i]] = 1;
                q.push({p.first * v[i], i});
            }
        }
        q.pop();
    }
    for(i=1;i<=n;i++)res += m[i];
    cout << res + 1 << endl;
    return 0;
}
