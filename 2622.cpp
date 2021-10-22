#include <iostream>

using namespace std;

int main(){
    int a,b;
    int n,res=0;

    cin >> n;
    for(a=1;a<=n/3;a++){
        for(b=a;b<=n;b++){
            if(n-a-b<b)break;
            if(n-a-b>=b && a+b>n-a-b)res++;
        }
    }
    cout << res << endl;
    return 0;
}