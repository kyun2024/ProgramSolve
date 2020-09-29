#include <iostream>

using namespace std;

int sel[8];
int n,m;

void q(int i,int c){
    sel[c]=i;
    if(c==m){
        for(int k=1;k<=m;k++){
            cout << sel[k] << " ";
        }
        cout << '\n';
        return;
    }
    for(int k=i;k<=n;k++){
        q(k,c+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    q(1,0);
    return 0;
}