#include <iostream>

using namespace std;

long long gcd(long long a,long long b)
{
    long long t;
    if(a<b)swap(a,b);
    while(b)
    {
        t = a%b;
        a = b;
        b = t;
    }
    return a;
}

int main(){
    long long a,b;
    cin >> a >> b;
    cout << a*b/gcd(a,b) << endl;
    return 0;
}
