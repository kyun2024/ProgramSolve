#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b>a)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    long long a,b;
    cin >> n;
    while(n--){
        cin >> a >> b;
        cout << a*b/gcd(a,b) << endl;
    }
    return 0;
}