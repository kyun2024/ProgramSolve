#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << 5*n-400 << endl;
    if(5*n-400>n)cout << -1 << endl;
    else if(5*n-400==n)cout << 0 << endl;
    else cout << 1 << endl;
    return 0;
}
