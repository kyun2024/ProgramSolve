#include <iostream>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n,m;
    int i;
    cin >> n >> m;
    for(i=1;i<=min(n,m);i++){
        if(n%i==0 && m%i==0){
            cout << i << " " << n/i << " " << m/i << '\n';
        }
    }
    return 0;
}