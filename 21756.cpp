#include <iostream>

using namespace std;

int main(){
    int n,b=1;
    cin >> n;
    while(true){
        if((n&~b)<b){
            cout << b << endl;
            break;
        }
        b<<=1;
    }
    return 0;
}