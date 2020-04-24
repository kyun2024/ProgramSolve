#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

using ll = long long;

struct abc
{
    ll t, b, i; //top, bottom, index
    ll value()
    {
        return abs(t - b);
    }
};

abc toa[100001], boa[100001];  //top-ordered-array, bottom-ordered-array, the count of sticks : 100000, 1 base index
ll m_tb[100001], m_bt[100001]; // memo for top to bottom, memo for bottom to top

int n;
ll l, ans = 0;

void input()
{
    int i;
    cin >> n >> l;
    for (i = 1; i <= n; i++)
    {
        cin >> toa[i].t >> toa[i].b;
    }
}

void preprocess()
{
    int i;
    // top ordered
    sort(toa + 1, toa + n + 1, [](const abc &i, const abc &j) {
        if (i.t == j.t)
        {
            return i.b < j.b;
        }
        return i.t < j.t;
    });
    for (i = 1; i <= n; i++)
    {
        toa[i].i = i;
    }
    copy_n(toa + 1, n, boa + 1);
    sort(boa + 1, boa + n + 1, [](const abc &i, const abc &j) {
        if (i.b == j.b)
        {
            return i.t < j.t;
        }
        return i.b < j.b;
    });
    for (i = 1; i <= n; i++)
    {
        toa[boa[i].i].i = i;
    }
}

void process()
{
    int i, j;
    ll res;
    preprocess();
    //cout << "process" << endl;
    m_tb[1] = m_bt[1] = toa[1].value() + l;
    ans = max(m_tb[1], m_bt[1]);
    //cout << "memo: " << m_tb[1] << " " << m_bt[1] << endl;
    for (i = 2; i <= n; i++)
    {
        //top to bottom
        res = toa[i].value() + l;
        // cout << "top: " << i << " " << res << endl;
        // for(j=i-1; j>=1 && toa[i].t==toa[j].t; j--){
        //     //cout << i << " " << j << endl;
        //     res = max(res,m_bt[j]);
        // }
        if (toa[i].t == toa[i - 1].t)
        {
            res = m_bt[i - 1] + toa[i].value() + l;
            if(res < m_tb[i-1]-toa[i-1].value()+toa[i].value()){
                res = m_tb[i-1]-toa[i-1].value()+toa[i].value();
            }
        }
        m_tb[i] = res;
        ans = max(ans,m_tb[i]);

        //bottom to top
        res = boa[toa[i].i].value() + l;
        // cout << "bottom: " << toa[i].i << " " << res << endl;
        // for(j=toa[i].i-1; j>=1 && boa[toa[i].i].b==boa[j].b; j--){
        //     //cout << toa[i].i << " " << j << endl;
        //     res = max(res,m_tb[boa[j].i]);
        // }
        if (boa[toa[i].i].b == boa[toa[i].i - 1].b)
        {
            res = m_tb[boa[toa[i].i - 1].i] + boa[toa[i].i].value() + l;
            if(res < m_bt[boa[toa[i].i-1].i]-boa[toa[i].i-1].value()+boa[toa[i].i].value()){
                res = m_bt[boa[toa[i].i-1].i]-boa[toa[i].i-1].value()+boa[toa[i].i].value();   //redirection
            }
        }
        m_bt[i] = res;
        ans = max(ans,m_bt[i]);
        // cout << "memo: " << m_tb[i] << " " << m_bt[i] << endl;
    }
}

void output()
{
    int i;
    // cout << "TOA" << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << setw(3) << toa[i].t << setw(3) << toa[i].b << setw(3) << abs(toa[i].t - toa[i].b) + l << setw(3) << toa[i].i << endl;
    // }
    // cout << "BOA" << endl;
    // for (i = 1; i <= n; i++)
    // {
    //     cout << setw(3) << boa[i].t << setw(3) << boa[i].b << setw(3) << abs(boa[i].t - boa[i].b) + l << setw(3) << boa[i].i << endl;
    // }
    cout << ans << endl;
}

int main()
{
    //input
    input();
    //process
    process();
    //output
    output();
}