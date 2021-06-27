#include <iostream>
#include <cstdlib>

using namespace std;

int m[10001];

int main(){
    int n;
    cin >> n;
    int i,j;
    long long res=0;
    for(i=1;i<=n;i++)cin >> m[i];
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)res += abs(m[i]-m[j]);
    cout << res << endl;
    return 0;
}