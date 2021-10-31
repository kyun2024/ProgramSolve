#include <iostream>

using namespace std;

int main(){
    int a,b,c,d;
    int n,res;
    int x=3;
    cin >> a >> b >> c >> d;
    while(x--)
    {
        res = 0;
        cin >> n;
        res += ((n-1)%(a+b)) < a;
        res += ((n-1)%(c+d)) < c;
        cout << res << endl;
    }
    return 0;
}