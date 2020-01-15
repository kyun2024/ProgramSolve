#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n,m;

void q(int a,int c){
    v[c]=a;
    if(c==m){
        for(int i=1;i<=m;i++){
            cout << v[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i=a+1;i<=n;i++){
        q(i,c+1);
    }
}

int main(){
    cin >> n >> m;
    v.resize(m+1);
    q(0,0);
    return 0;
}