#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int n,n0{},n1{},n2{},a;
    cin >> n;
    while(n--)
    {
        cin >> a;
        if(a%3==0)
        {
            n0++;
        }
        else if(a%3==1)
        {
            n1++;
        }
        else n2++;
    }
    cout << fixed << (n1-n2) << " " << n0-n2 << endl;
    return 0;
}