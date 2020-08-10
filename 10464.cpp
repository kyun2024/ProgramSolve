#include <iostream>

using namespace std;

int xor_number(int n){
    switch(n%4){
    case 0:
        return n;
    case 1:
        return 1;
    case 2:
        return n+1;
    case 3:
        return 0;
    }
}

int main(){
    int T,a,b;
    cin >> T;
    while(T--){
        cin >> a >> b;
        cout << (xor_number(a-1)^xor_number(b)) << endl;
    }
}