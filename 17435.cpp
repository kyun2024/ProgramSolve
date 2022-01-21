#include <iostream>

using namespace std;

int n_map[200001][20];

void proc(int &m);

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int i;
    int m,q;
    int n,x;
    cin >> m;
    for(i=1;i<=m;i++){
        cin >> n_map[i][0];
    }
    //proc
    proc(m);
    cin >> q;
    while(q--){
        cin >> n >> x;
        for(i=19;i>=0;i--)
        {
            if(n&(1<<i)){
                x = n_map[x][i];
            }
        }
        cout << x << '\n';
    }

    return 0;
}

void proc(int &m){
    int i,j;
    for(i=1;i<=19;i++){
        for(j=1;j<=m;j++){
            n_map[j][i]=n_map[n_map[j][i-1]][i-1];
        }
    }
}