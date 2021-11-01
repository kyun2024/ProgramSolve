#include <iostream>

using namespace std;

int main(){
    int n,m;
    int res=0;
    cin >> n >> m;
    while(n>0){
        res += n;
        n /= m;
    }
    cout << res << endl;
    return 0;
    
}