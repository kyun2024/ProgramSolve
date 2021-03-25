#include <iostream>

using namespace std;

int m[51];

int main(){
    m[0]=m[1]=1;
    int i;
    for(i=2;i<=50;i++)
    {
        m[i]=(m[i-1]+m[i-2]+1)%1000000007;
    }
    cin >> i;
    cout << m[i] << endl;
    return 0;
}