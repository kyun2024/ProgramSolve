#include <iostream>

using namespace std;

int main(){
    int n;
    while(1){
        cin >> n;
        if(n==0)break;
        if(n>5000000){
            n *= 0.8;
        }
        else if(n>1000000){
            n *= 0.9;
        }
        cout << n << endl;
    }
    return 0;
}