#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    int f,t;
    int a[100001]={0,};
    int s[100001]={0,};

    
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=m;i++){
        cin >> f >> t;
        cout << s[t]-s[f-1] << '\n';
    }
    return 0;
}