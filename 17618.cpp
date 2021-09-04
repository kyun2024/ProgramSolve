#include <iostream>

using namespace std;

int main(){
    int n,t1,t2,i,res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        t1 = i;
        t2 = 0;
        while(t1){
            t2 += t1%10;
            t1/=10;
        }
        res += i%t2==0;
    }
    cout << res << endl;
    return 0;
}
