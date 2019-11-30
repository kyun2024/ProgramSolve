#include <iostream>

using namespace std;

int main(){
    int n,i;
    long long a1,a2,res;
    cin >> n;
    res = a1 = 0;
    if(n==0){
        goto PRINT;
    }
    res = a2 = 1;
    if(n==1){
        goto PRINT;
    }
    for(i=2;i<=n;i++){
        res = a1+a2;
        a1 = a2;
        a2 = res;
    }
PRINT:
    cout << res << endl;
    return 0;
}