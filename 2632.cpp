#include <iostream>

using namespace std;

int apizza[1000];
int bpizza[1000];

int app[1000001];
int bpp[1000001];

int main()
{
    int w, res;
    int n, m, s;
    int i, j;
    cin >> w;
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        cin >> apizza[i];
        app[apizza[i]]++;
    }
    for (i = 0; i < m; i++)
    {
        cin >> bpizza[i];
        bpp[bpizza[i]]++;
    }
    //a
    // for(i=0;i<n;i++)cout << apizza[i] << " ";
    // cout << endl;
    for (i = 1; i < n - 1; i++)
    {
        s = 0;
        for (j = 0; j <= i; j++)
        {
            s += apizza[j];
        }
        for (j = 0; j < n; j++)
        {
            s = s - apizza[j] + apizza[(j + i + 1) % n];
            // cout << s << " ";
            app[s]++;
        }
        // cout << endl;
    }
    if (n > 1)
    {
        s = 0;
        for (j = 0; j < n; j++)
            s += apizza[j];
        app[s]++;
    }
    // cout << s << endl;
    //b
    // for(i=0;i<m;i++)cout << bpizza[i] << " ";
    // cout << endl;
    for (i = 1; i < m - 1; i++)
    {
        s = 0;
        for (j = 0; j <= i; j++)
        {
            s += bpizza[j];
        }
        for (j = 0; j < m; j++)
        {
            s = s - bpizza[j] + bpizza[(j + i + 1) % m];
            // cout << s << " ";
            bpp[s]++;
        }
        // cout << endl;
    }
    if (m > 1)
    {
        s = 0;
        for (j = 0; j < m; j++)
            s += bpizza[j];
        bpp[s]++;
    }
    // cout << s << endl;
    //res
    app[0] = bpp[0] = 1;
    res = 0;
    for (i = max(0, w - 1000000); i <= min(w, 1000000); i++)
    {
        //cout << i << " " << w-i << endl;
        res += app[i] * bpp[w - i];
    }
    cout << res << endl;
}