#include <iostream>

using namespace std;

int pc[101];

int main(){
    int res=0;
    int n,i,a;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a;
        pc[a]++;
    }
    for(i=1;i<=100;i++){
        res += max(pc[i]-1,0);
    }
    cout << res << endl;
    return 0;
}