#include <iostream>

using namespace std;

int main(){
    int p,q,i,j;
    cin >> p >> q;
    for(i=1;i<=p;i++)for(j=1;j<=q;j++)if(p%i==0 && q%j==0)cout << i << " " << j << '\n';
    return 0;
}
