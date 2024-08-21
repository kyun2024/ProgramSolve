#include <iostream>

using namespace std;
using ll = long long;

ll dc[30], sdc[30];
ll e10[19];

int main()
{
    int i;
    e10[0] = 1;
    for(i=1;i<=18;++i)e10[i]=10*e10[i-1];
    for(i=1;i<=30;++i)
    {
        dc[i] = i * 9 * e10[(i-1)/2];
        sdc[i] = dc[i] + sdc[i-1];
    }
    ll nth;
    cin >> nth;
    for(i=1;i<=30 && nth > sdc[i];++i);
    nth = nth - 1 - sdc[i-1];
    ll num_nth = nth/i;
    ll pos_nth = nth%i;
    if(pos_nth == 0)
        cout << 1+num_nth/e10[(i-1)/2 - pos_nth]%10;
    else if(pos_nth == i-1)
        cout << 1+num_nth/e10[(pos_nth - i/2)]%10;
    else if(pos_nth <= (i-1)/2)
        cout << num_nth/e10[(i-1)/2 - pos_nth]%10;
    else
        cout << num_nth/e10[(pos_nth - i/2)]%10;
    cout << endl;
    return 0;
}