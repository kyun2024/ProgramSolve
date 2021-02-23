#include <iostream>
#include <cmath>

using namespace std;

int seg_a[400000];
int dt_a[100000];
char sc[][2]={"-","0","+"};

int init(int n, int s, int e)
{
    if (s == e)
    {
        return seg_a[n] = dt_a[e];
    }
    return seg_a[n] = init(2 * n, s, (s + e) / 2) * init(2 * n + 1, (s + e) / 2 + 1, e);
}

int get_node(int n, int s, int e, int i)
{
    while (s != e)
    {
        if (i <= (s + e) / 2)
        {
            n = 2 * n;
            e = (s+e)/2;
        }
        else
        {
            n = 2 * n + 1;
            s = (s+e)/2+1;
        }
    }
    return n;
}

void update(int n, int sn)
{
    seg_a[n] = sn;
    n = n / 2;
    while (n > 0)
    {
        seg_a[n] = seg_a[2 * n] * seg_a[2 * n + 1];
        n = n / 2;
    }
}

int seg_sign(int n, int s, int e, int rb, int re)
{
    if (re < s || e < rb)
    {
        return 1;
    }
    if (rb <= s && e <= re)
    {
        return seg_a[n];
    }
    return seg_sign(2 * n, s, (s + e) / 2, rb, re) * seg_sign(2 * n + 1, (s + e) / 2+1, e, rb, re);
}

int sign(int n)
{
    if (n > 0){
        n = 1;
    }
    else if (n < 0){
        n = -1;
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q, x;
    int i;
    int x1, x2;
    string str;
    while (true)
    {
        cin >> n;
        if (cin.eof())
            break;
        cin >> q;
        for (i = 0; i < n; i++)
        {
            cin >> x;
            dt_a[i] = sign(x);
        }
        init(1, 0, n - 1);
        for (i = 0; i < q; i++)
        {
            cin >> str >> x1 >> x2;
            if (str == "C")
            { 
                //update
                update(get_node(1, 0, n - 1, x1 - 1), sign(x2));
            }
            else{
                //print
                cout << sc[seg_sign(1,0,n-1,x1-1,x2-1)+1];
            }
            cin.get();
        }
        cout << '\n';
    }
    return 0;
}