#include <iostream>

using namespace std;

int m[41];

int main(){
    int n,i;
    m[1]=m[2]=1;
    for(i=3;i<=40;i++)m[i]=m[i-1]+m[i-2];
    cin >> n;
    cout << m[n] << " " << n-2 << endl;
    return 0;
}
