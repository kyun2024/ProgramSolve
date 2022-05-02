#include <iostream>

using namespace std;

int main(){
    int c=0,n;
    cin >> n;
    int i;
    for(i=1;i<=n;i++){
        if(n%i==0)c+=i;
    }
    cout << c*5-24 << endl;
    return 0;
}
