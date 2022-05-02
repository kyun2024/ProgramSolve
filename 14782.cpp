#include <iostream>

using namespace std;

int main(){
    int n,c{},i;
    cin >> n;
    for(i=1;i<=n;i++){
        if(n%i==0)c+=i;
    }
    cout << c << endl;
    return 0;
}
