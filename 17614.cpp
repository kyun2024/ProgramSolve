#include <iostream>

using namespace std;

int main(){
    int i,n,res=0,t;
    cin >> n;
    for(i=1;i<=n;i++)for(t=i;t>0;t/=10)res += t%10%3==0 && t%10!=0;
    cout << res << endl;
    return 0;
}