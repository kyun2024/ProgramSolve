#include <iostream>

using namespace std;

int main(){
    int n{},i,j,t;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(i=0;i<n;i++){
        cin >> t;
        for(j=0;t>0;j++){
            if(t&1){
                cout << j << " ";
            }
            t>>=1;
        }
        cout << '\n';
    }
    return 0;
}