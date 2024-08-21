#include <iostream>
#include <algorithm>

using namespace std;
using ll = long long;

ll _2exp[300001];
ll A[300001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int i;
    _2exp[0]=1;
    for(i=1;i<=300000;++i)_2exp[i] = (2 * _2exp[i-1])%1'000'000'007;
    int N;
    cin >> N;
    for(i=0;i<N;++i)cin >> A[i];
    ll res = 0;
    sort(A, A+N);
    for(i=0;i<N;++i)res = (res + A[i] * (_2exp[i] - _2exp[N-i-1]))%1'000'000'007;
    cout << res << endl;
}