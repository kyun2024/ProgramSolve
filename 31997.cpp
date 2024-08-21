#include <iostream>

using namespace std;

int m[400001];
int dur[200000][2];
int fri[200000][2];

pair<int, int> and_dur(int i, int j)
{
    auto [bi, ei] = dur[i];
    auto [bj, ej] = dur[j];
    if(ei <= bj || ej <= bi)return {-1, -1};
    if(bi <= bj && ej <= ei)return {bj, ej};
    if(bj <= bi && ei <= ej)return {bi, ei};
    return {max(bi, bj), min(ei, ej)};
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, M, T;
    cin >> N >> M >> T;
    int i;
    for(i=0;i<N;++i)
    {
        cin >> dur[i][0] >> dur[i][1];
    }
    for(i=0;i<M;++i)
    {
        cin >> fri[i][0] >> fri[i][1];
        auto [b, e] = and_dur(fri[i][0]-1, fri[i][1]-1);
        // cout << fri[i][0]-1 << " " << fri[i][1]-1 << " " << b << " " << e << endl;
        if(b != -1 && e != -1)
        {
            ++m[2*b];
            --m[2*e];
        }
    }
    // for(i=0;i<=2*T;++i)
    // {
    //     cout << m[i] << " ";
    // }
    // cout << endl;
    for(i=1;i<=2*T;++i)
    {
        m[i] = m[i] + m[i-1];
    }
    for(i=1;i<=2*T;++++i)
    {
        cout << m[i] << '\n';
    }
    return 0;
}