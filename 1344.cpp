#include <iostream>

using namespace std;

double f(double p, int c, int n)
{
    if(n==0)
    {
        return !(c==2 || c==3 || c==5 || c==7 || c==11 || c==13 || c==17);
    }
    return (1-p)*f(p, c, n-1) + p*f(p, c+1, n-1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << 1.0 - f(a/100.0, 0, 18)*f(b/100.0, 0, 18) << endl;
}