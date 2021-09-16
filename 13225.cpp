#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    int n,c,i;
    while(t--){
        cin >> n;
        c=0;
        for(i=1;i<=n;i++)c+=n%i==0;
        cout << n << " " << c << endl;
    }
    return 0;
}