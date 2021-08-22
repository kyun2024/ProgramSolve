#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int res=0;
    for(int i=min(5,n);i>=n-i;i--){
        res++;
    }
    cout << res << endl;
    return 0;
}