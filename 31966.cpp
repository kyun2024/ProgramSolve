#include <iostream>

using namespace std;

long long T[100001];
long long L[100001];
long long R[100001];
long long C[100001];

constexpr int MOD = 1e9+7;

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i, l, r;
    int N;

    // init
    T[0] = L[0] = R[0] = C[0] = 1;

    cin >> N;
    for(i=1;i<=N;++i)
    {
        cin >> l >> r;
        T[i] = (T[l] + T[r] + L[l] * C[r] + R[r] * C[l] - 1)%MOD;
        L[i] = (L[r] + L[l] + C[l] - 1)%MOD;
        R[i] = (R[l] + R[r] + C[r] - 1)%MOD;
        C[i] = (C[l] + C[r])%MOD;
        cout << T[i] << '\n';
    }
}