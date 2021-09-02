#include <iostream>

using namespace std;

int main(){
    int s=0;
    int n,k;
    cin >> n >> k;
    while(k-->=0){
        s += n;
        n *= 10;
    }
    cout << s << endl;
    return 0;
}