#include <iostream>

using namespace std;

int main(){
    unsigned long long n,res=0,i;
    cin >> n;
    for(i=1;i<n;i++){
        res += (n*i+i);
    }
    cout << res << endl;
    return 0;
}