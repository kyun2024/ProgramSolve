#include <iostream>

using namespace std;

int main(){
    int a,b;
    int rev_a{},rev_b{};
    cin >> a >> b;
    while(a>0){
        rev_a = 10*rev_a + a%10;
        a/=10;
    }
    while(b>0){
        rev_b = 10*rev_b + b%10;
        b/=10;
    }
    cout << max(rev_a,rev_b) << endl;
    return 0;
}