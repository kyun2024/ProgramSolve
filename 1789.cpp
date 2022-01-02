#include <iostream>

using namespace std;

int main(){
    long long n,i;
    cin >> n;
    for(i=1;i<=141421;i++){
        if(n == i*(i+1)/2){
            cout << i << endl;
            break;
        }
        if(n < i*(i+1)/2){
            cout << i-1 << endl;
            break;
        }
    }
    return 0;
}