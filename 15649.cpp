#include <iostream>
#include <vector>

using namespace std;

vector<int> p;
vector<int> c;

int n,m;

void q(int a,int cnt){
    p[cnt]=a;
    c[a]=1;
    if(cnt==m){
        for(int i=1;i<=m;i++){
            cout << p[i] << " ";
        }
        cout << '\n';
        c[a]=0;
        return;
    }
    for(int i=1;i<=n;i++){
        if(!c[i]){
            q(i,cnt+1);
        }
    }
    c[a]=0;
}

int main(){
    cin >> n >> m;
    p.resize(m+1);
    c.resize(n+1,0);
    q(0,0);
}