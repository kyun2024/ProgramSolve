#include <iostream>

using namespace std;

bool c[3125][3125];
bool default_pattern[5][5] = {
    {0, 0, 1, 0, 0,},
    {0, 0, 1, 0, 0,},
    {1, 1, 1, 1, 1,},
    {0, 1, 1, 1, 0,},
    {0, 1, 0, 1, 0,},
};

template <int N, int T>
struct Exp{
    static const int res = N * Exp<N, T-1>::res;
};

template <int N>
struct Exp<N, 0>
{
    static const int res = 1;
};

int d[] = {Exp<5, 0>::res, Exp<5, 1>::res, Exp<5, 2>::res, Exp<5, 3>::res, Exp<5, 4>::res, Exp<5, 5>::res};

void check(int x, int y, int r)
{
    if(r==1)
    {
        c[y][x] = 1;
        return;
    }
    int i,j;
    for(i=0;i<5;++i)
    {
        for(j=0;j<5;++j)
        {
            if(default_pattern[i][j])
            {
                check(x+j*r/5, y+i*r/5, r/5);
            }
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    cin >> n;
    check(0, 0, d[n]);
    for(int i=0;i<d[n];++i)
    {
        for(int j=0;j<d[n];++j)
        {
            cout << (c[i][j]?"*":" ");
        }
        cout << '\n';
    }
    return 0;
}