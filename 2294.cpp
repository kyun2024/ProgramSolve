#include <iostream>
#include <algorithm>
#include <queue>

int m[10001];
int c[101];

using namespace std;

struct qe{
    int n,c;
};

int main(){
    int n,k,i,rk{};
    cin >> n >> k;
    for(i=1;i<=n;i++)cin >> c[i];
    sort(c+1,c+n+1,less<int>());
    rk=1;
    for(i=2;i<=n;i++)
    {
        if(c[i-1]!=c[i]){
            rk++;
            c[rk]=c[i];
        }
    }
    qe f;
    queue<qe> q;
    q.push({k,0});
    while(!q.empty() && m[0]==0){
        f = q.front();
        for(i=1;i<=rk;i++){
            if(f.n-c[i]>=0 && m[f.n-c[i]]==0){
                m[f.n-c[i]]=f.c+1;
                q.push({f.n-c[i],f.c+1});
            }
        }
        q.pop();
    }
    m[0] = (m[0]==0?-1:m[0]);
    cout << m[0] << endl;
    return 0;
}