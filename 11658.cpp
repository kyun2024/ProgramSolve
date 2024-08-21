#include <iostream>
#include <iterator>

using namespace std;
using ll = long long;

ll seg_tree[1025*4][1025*4];
ll aa[1025][1025];

void print_list(std::initializer_list<int> il) {
    std::copy(il.begin(), il.end(), std::ostream_iterator<int>(std::cout, ", "));
};

void sis_update(int row_n, int col_n, int col_l, int col_r, int c, ll diff)
{
    while(col_l != col_r)
    {
        seg_tree[row_n][col_n] += diff;
        // cout << "update col : " << col_l << " " << col_r << endl;
        int m = (col_l+col_r)/2;
        if(c <= m)
        {
            col_n = 2*col_n;
            col_r = m;
        }
        else
        {
            col_n = 2*col_n+1;
            col_l = m+1;
        }
    }
    seg_tree[row_n][col_n] += diff;
}

void update(int row_l, int row_r, int col_l, int col_r, int r, int c, ll diff)
{
    int row_n = 1, col_n = 1;
    while(row_l != row_r)
    {
        sis_update(row_n, 1, col_l, col_r, c, diff);
        // cout << "update row : " << row_l << " " << row_r << endl;
        int m = (row_l+row_r)/2;
        if(r <= m)
        {
            row_n = 2*row_n;
            row_r = m;
        }
        else
        {
            row_n = 2*row_n+1;
            row_l = m+1;
        }
    }
    sis_update(row_n, 1, col_l, col_r, c, diff);
    // cout << "update aa : " << row_l << " " << col_r << endl;
    // cout << "diff : " << diff << endl;
    aa[r][c] += diff;
}

ll sis_query(int row_n, int n, int col_l, int col_r, int q_col_l, int q_col_r)
{
    if(col_r < q_col_l || q_col_r < col_l)return 0;
    if(q_col_l <= col_l && col_r <= q_col_r)
    {
        // cout << "sis_query("; print_list({row_n, n, col_l, col_r, q_col_l, q_col_r}); cout << ") return : " << seg_tree[row_n][n] << endl;
        return seg_tree[row_n][n];
    }
    int m = (col_l + col_r)/2;
    ll res = sis_query(row_n, 2*n, col_l, m, q_col_l, q_col_r) + sis_query(row_n, 2*n+1, m+1, col_r, q_col_l, q_col_r);
    return res;
}

ll query(int n, int row_l, int row_r, int col_l, int col_r, int q_row_l, int q_row_r, int q_col_l, int q_col_r)
{
    if(row_r < q_row_l || q_row_r < row_l)return 0;
    if(q_row_l <= row_l && row_r <= q_row_r)
    {
        ll res = sis_query(n, 1, col_l, col_r, q_col_l, q_col_r);
        // cout << "query("; print_list({n, row_l, row_r, col_l, col_r, q_row_l, q_row_r, q_col_l, q_col_r}); cout << ") return : " << res << endl;
        return res;
    }
    int m = (row_l + row_r)/2;
    return query(2*n, row_l, m, col_l, col_r, q_row_l, q_row_r, q_col_l, q_col_r) + query(2*n+1, m+1, row_r, col_l, col_r, q_row_l, q_row_r, q_col_l, q_col_r);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, Q;
    ll r, c, w, v;
    cin >> N >> Q;
    for(r=1;r<=N;++r)
    {
        for(c=1;c<=N;++c)
        {
            cin >> v;
            update(1, N, 1, N, r, c, v);
        }
    }
    for(int i=0;i<Q;++i)
    {
        cin >> w;
        if (w == 1)
        {
            ll row_l, col_l, row_r, col_r;
            cin >> row_l >> col_l >> row_r >> col_r;
            cout << query(1, 1, N, 1, N, row_l, row_r, col_l, col_r) << '\n';
        }
        else
        {
            ll new_val;
            cin >> r >> c >> new_val;
            update(1, N, 1, N, r, c, new_val - aa[r][c]);
        }
    }
    return 0;
}