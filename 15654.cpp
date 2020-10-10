#include <iostream>
#include <algorithm>

using namespace std;

int a[9];
int sel[9];
int ch[9];
int n,m;

void q(int i,int c){
    sel[c]=i;
    ch[i]=1;
    if(c==m){
        for(int k=1;k<=m;k++){
            cout << a[sel[k]] << " ";
        }
        cout << '\n';
        ch[i]=0;
        return;
    }
    for(int k=1;k<=n;k++){
        if(ch[k]==0)q(k,c+1);
    }
    ch[i]=0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    q(0,0);
    return 0;
}