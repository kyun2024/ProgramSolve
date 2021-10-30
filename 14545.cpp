#include <iostream>

using namespace std;

int m[1000001];

int main(){
    int t,i;
    for(i=1;i<=1000000;i++){
        m[i]=i*i+m[i-1];
    }
    cin >> t;
    while(t--){
        cin >> i;
        cout << m[i] << '\n';
    }
    return 0;
}