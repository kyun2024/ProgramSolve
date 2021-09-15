#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    while (true)
    {
        cin >> a >> b >> c;
        if(a==0 && b==0 && c==0)break;
        if(a==0) a = c/b;
        if(b==0) b = c/a;
        if(c==0) c=a*b;
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}