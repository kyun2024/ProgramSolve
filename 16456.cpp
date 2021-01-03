#include <iostream>

using namespace std;

int ma[50001],mb[50001];

int main(){
    int n,i;
    cin >> n;
    ma[1]=1;
    for(i=2;i<=n;i++){
        ma[i]=(ma[i-1]+mb[i-1])%1000000009;
        mb[i]=ma[i-2];
    }
    cout << (ma[n]+mb[n])%1000000009 << endl;
    return 0;
}