#include <iostream>

using namespace std;

int main(){
    long long a,b,i,res=1;
    cin >> a >> b;
    for(i=a;i<=b;i++){
        res *= i*(i+1)/2;
        res %= 14579;
    }
    cout << res << endl;
    
}