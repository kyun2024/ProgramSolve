#include <iostream>
#include <queue>

using namespace std;

int main(){
    long long n,m;
    queue<pair<long long,size_t>> q;
    cin >> n >> m;
    q.push(make_pair(n,1));
    while(!q.empty()){
        pair<long long,size_t> cur = q.front();
        if(cur.first==m){
            cout << cur.second << endl;
            return 0;
        }
        if(cur.first*10+1 <= m){
            q.push(make_pair(cur.first*10+1,cur.second+1));
        }
        if(cur.first*2 <= m){
            q.push(make_pair(cur.first*2,cur.second+1));
        }
        q.pop();
    }
    cout << -1 << endl;
    return 0;
}