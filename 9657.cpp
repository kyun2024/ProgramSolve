#include <iostream>

using namespace std;

int m[1001];

int main(){
    m[1]=m[3]=m[4]=1;
    int i;
    for(i=5;i<=1000;i++){
        m[i] = !(m[i-1]&m[i-3]&m[i-4]);
    }
    cin >> i;
    cout << (m[i]?"SK":"CY") << endl;
    return 0;
}