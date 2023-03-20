#include <iostream>

using namespace std;

int min_tr[1000001];

int main()
{
    int a,k,i;
    cin >> a >> k;
    min_tr[a] = 1;
    for(i=a+1;i<=k;i++)
    {
        if(i%2 == 0 && i/2 >= a) min_tr[i] = min_tr[i/2] + 1;
        else min_tr[i] = min_tr[i-1] + 1;
    }
    cout << min_tr[k]-1 << endl;
    return 0;
}