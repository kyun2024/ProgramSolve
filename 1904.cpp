#include <iostream>

using namespace std;

int main(){
    int n;
    int a1,a2,i,res;
    cin >> n;
    res = a1 = 1;
    if(n==1){
        goto PRINT;
    }
    res = a2 = 2;
    if(n==2){
        goto PRINT;
    }
    for(i=3;i<=n;i++){
        res = (a1+a2)%15746;
        a1 = a2;
        a2 = res;
    }
PRINT:
    cout << res << endl;
    return 0;
}