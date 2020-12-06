#include <iostream>
#include <algorithm>

using namespace std;

int a[9];
int sel[9];
int n,m;

void q(int i,int c){
    sel[c]=i;
    if(c==m){
        for(int k=1;k<=m;k++){
            cout << a[sel[k]] << " ";
        }
        cout << '\n';
        return;
    }
    for(int k=1;k<=n;k++){
        q(k,c+1);
    }
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