#include <iostream>

using namespace std;

int main(){
    int n,res{},a,b;
    cin >> n;
    while(--n>=0){
        cin >> a >> b;
        res += a*b;
    }
    cout << res << endl;
    return 0;
}