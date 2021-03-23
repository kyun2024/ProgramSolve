#include <iostream>
#include <algorithm>

using namespace std;

int p[1001];

int main(){
    int max_rev=0,max_pr=0;
    int n,m;
    int i,j;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> p[i];
    }
    sort(p+1,p+m+1,greater<>());
    max_rev = max_pr = p[1];
    for(i=2;i<=min(n,m);i++){
        if(max_rev<p[i]*i){
            max_pr = p[i];
            max_rev = p[i]*i;
        }
    }
    cout << max_pr << " " << max_rev << endl;
    return 0;
}