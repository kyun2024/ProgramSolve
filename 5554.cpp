#include <iostream>

using namespace std;

int main(){
    int total=0,t,n=4;
    while(--n>=0){
        cin >> t;
        total += t;
    }
    cout << total / 60 << endl << total % 60 << endl;
    return 0;
}