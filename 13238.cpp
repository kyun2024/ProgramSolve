#include <iostream>

using namespace std;

int p[10001];

int main(){
    int n;
    int i,j;
    int res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> p[i];
    }
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j++){
            res = max(res, p[j]-p[i]);
        }
    }
    cout << res << endl;
    return 0;
}