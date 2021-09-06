#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int T;
    int n;
    bitset<10> b;
    cin >> T;
    while(T--){
        b = 0;
        cin >> n;
        if(n==0){
            b=1;
        }
        while(n){
            b.set(n%10);
            n/=10;
        }
        cout << b.count() << endl;
    }
    return 0;
}