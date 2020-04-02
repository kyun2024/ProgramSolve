#include <iostream>

using namespace std;

int main(){
    int r2{},r5{};
    int n,i,j;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=i;j%2==0;j/=2,r2++);
        for(j=i;j%5==0;j/=5,r5++);
    }
    cout << min(r2,r5) << endl;
    return 0;
}