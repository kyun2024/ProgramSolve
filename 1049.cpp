#include <iostream>

using namespace std;

int main(){
    int n,m;
    int v6,v1,a,b,i;
    cin >> n >> m;
    cin >> v6 >> v1;
    if(6*v1<v6)v6=6*v1;
    for(i=1;i<m;i++){
        cin >> a >> b;
        v6 = min(v6,a);
        v6 = min(v6,6*b);
        v1 = min(v1,b);
    }
    cout << min(min((n+5)/6*v6,n*v1),(n/6)*v6+(n%6)*v1) << endl;
    return 0;
}