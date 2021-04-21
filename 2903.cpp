#include <iostream>

using namespace std;

int main(){
    int n;
    int r=1,i;
    cin >> n;
    for(i=1;i<=n;i++){
        r*=2;
    }
    cout << (r+1)*(r+1) << endl;
}