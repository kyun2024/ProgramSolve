#include <iostream>
#include <memory.h>

using namespace std;

int N, M;
int D[1001];
int K[7][1001];
int perm[7];
bool check[8];
int res = -1;
int forgot_date[1001];

void brute_force(int c)
{
    if(c == M)
    {
        int cnt = 0;
        memset(forgot_date, 0, sizeof(forgot_date));
        for(int i=0;i<M;++i)
        {
            for(int j=0, p = K[perm[i]][j];p != 0;++j, p = K[perm[i]][j])
            {
                if(forgot_date[p] <= i)
                {
                    forgot_date[p] = i + D[p];
                    ++cnt;
                }
            }
        }
        if(res<0)res = cnt;
        else res = min(res, cnt);
        // for(int i=0;i<N;++i)cout << perm[i] << " ";
        // cout << ": " << cnt << endl;
        return;
    }
    for(int i=0;i<M;++i)
    {
        if(!check[i])
        {
            check[i]=1;
            perm[c] = i;
            brute_force(c+1);
            check[i]=0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int a, i, j;
    cin >> N >> M;
    for(i=1;i<=N;++i)cin >> D[i];
    for(i=0;i<M;++i)
    {
        cin >> a;
        for(j=0;j<a;++j)
        {
            cin >> K[i][j];
        }
    }
    brute_force(0);
    cout << res << endl;
    return 0;
}