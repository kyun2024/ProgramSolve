#include <iostream>

using namespace std;

int main(){
    int n,res=0;
    cin >> n;
    int i=1,s=0;
    while(s<n){
        if((n-s)%i==0)res++;
        s += i;
        i++;
    }
    cout << res << endl;
    return 0;
}