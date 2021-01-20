#include <iostream>

using namespace std;

int main(){
    int n,i,res=0;
    cin >> n;
    while(n!=0){
        for(i=1;n-i>=0;i++){
            n -= i;
            res++;
        }
    }
    cout << res << endl;
    return 0;
}