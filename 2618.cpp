#include <iostream>
#include <math.h>

using namespace std;

int m_pos[1001][2];
int m[1001][1001];
pair<int,int> bt[1001][1001];
int N;

int f_d(int r0, int c0, int r1, int c1)
{
    return abs(r0-r1)+abs(c0-c1);
}

void print_bt(int r,int c)
{
    if(r==0 && c==0)return;
    pair<int,int> bt_p = bt[r][c];
    print_bt(bt_p.first, bt_p.second);
    //cout << "(" << r << ", " << c << ") " << (r>c?1:2) << '\n';
    cout << (r>c?1:2) << '\n';
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int M;
    int i, j;
    cin >> N >> M;
    for(i=1;i<=M;i++)
    {
        cin >> m_pos[i][0] >> m_pos[i][1];
    }
    m[1][0] = f_d(1, 1, m_pos[1][0], m_pos[1][1]);
    m[0][1] = f_d(N, N, m_pos[1][0], m_pos[1][1]);
    for(i=2;i<=M;i++)
    {
        for(j=0;j<i-1;j++)
        {
            m[j][i] = m[j][i-1] + f_d(m_pos[i-1][0], m_pos[i-1][1], m_pos[i][0], m_pos[i][1]);
            bt[j][i] = {j, i-1};
            m[i][j] = m[i-1][j] + f_d(m_pos[i-1][0], m_pos[i-1][1], m_pos[i][0], m_pos[i][1]);
            bt[i][j] = {i-1, j};
        }
        m[i][i-1] = m[0][i-1]+f_d(1, 1, m_pos[i][0], m_pos[i][1]);
        bt[i][i-1] = {0, i-1};
        m[i-1][i] = m[i-1][0]+f_d(N, N, m_pos[i][0], m_pos[i][1]);
        bt[i-1][i] = {i-1, 0};
        for(j=1;j<i-1;j++)
        {
            if(m[j][i-1] + f_d(m_pos[j][0], m_pos[j][1], m_pos[i][0], m_pos[i][1]) < m[i][i-1])
            {
                m[i][i-1] = m[j][i-1]+f_d(m_pos[j][0], m_pos[j][1], m_pos[i][0], m_pos[i][1]);
                bt[i][i-1] = {j, i-1};
            }
            if(m[i-1][j]+f_d(m_pos[j][0], m_pos[j][1], m_pos[i][0], m_pos[i][1]) < m[i-1][i])
            {
                m[i-1][i] = m[i-1][j]+f_d(m_pos[j][0], m_pos[j][1], m_pos[i][0], m_pos[i][1]);
                bt[i-1][i] = {i-1, j};
            }
        }
    }
    int min_dist=987654321, min_r, min_c;
    for(i=0;i<M;i++)
    {
        if(min_dist > m[i][M])
        {
            min_dist = m[i][M];
            min_r = i;
            min_c = M;
        }
        if(min_dist > m[M][i])
        {
            min_dist = m[M][i];
            min_r = M;
            min_c = i;
        }
    }
    cout << min_dist << '\n';
    print_bt(min_r, min_c);
    return 0;
}