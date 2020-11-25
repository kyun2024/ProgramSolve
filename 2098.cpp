#include <iostream>
#include <bitset>

using namespace std;

int w[16][16];
int m[16][(1 << 16)];
bool chk[16][(1 << 16)];

int n;

constexpr int bitset_n=4;

int f(int c, int v)
{
    //cout << "f(" << c << ", " << bitset<bitset_n>(v).to_string() << ") \n";
    if (chk[c][v]){
        //cout << "checked\n";
        return m[c][v];
    }
    v &= ~(1 << c);
    if (v == 1)
    {
        //cout << "w[0, " << c << "] : " << w[0][c] << "\n";
        return w[0][c];
    }
    int i, min_val = 1e8, t;
    for (i = 1; i < n; i++)
    {
        if (w[i][c] != 0 && (v & (1 << i)) != 0)
        {
            t = f(i, v);
            if (t != 0)
            {
                min_val = min(min_val, t+w[i][c]);
            }
        }
    }
    v |= (1 << c);
    chk[c][v] = true;
    if (min_val == 1e8)
    {
        m[c][v] = 0;
    }
    else
    {
        m[c][v] = min_val;
    }
    //cout << "m[" << c << ", " << bitset<bitset_n>(v).to_string() << "]: " << m[c][v] << "\n";
    return m[c][v];
}

int main()
{
    int i, j;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> w[i][j];
        }
    }
    int res=1e8,t;
    for(i=1;i<n;i++){
        t = f(i,(1<<n)-1);
        if(t!=0 && w[i][0]!=0){
            res = min(res,t+w[i][0]);
        }
    }
    cout << res << endl;
    return 0;
}