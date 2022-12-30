#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int ori[500001];
int srt[500001];
int nrm[500001];
long long c[2000000];

void push_seg(int s, int e, int n)
{
    int node = 1;
    int m;
    stack<int> s_n;
    s_n.push(1);
    while(s<e)
    {
        m = (s+e)/2;
        if(n<=m)
        {
            e = m;
            node = 2 * node;
        }
        else
        {
            s = m + 1;
            node = 2 * node + 1;
        }
        s_n.push(node);
    }
    while(!s_n.empty())
    {
        c[s_n.top()]++;
        s_n.pop();
    }
}

long long find_seg(int s,int e,int n)
{
    if(n == 0)return 0;
    int node = 1;
    int m;
    long long res=0;
    while(s<e)
    {
        m = (s+e)/2;
        if(n < m)
        {
            e = m;
            node = 2 * node;
        }
        else if(n == m)
        {
            node = 2 * node;
            break;
        }
        else
        {
            res += c[2 * node];
            s = m + 1;
            node = 2 * node + 1;
        }
    }
    res += c[node];
    return res;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n,i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> ori[i];
        srt[i] = i;
    }
    sort(srt+1,srt+1+n,[](int i,int j)
    {
        return ori[i]<ori[j];
    });
    // cout << "d\n";
    // for(i=1;i<=n;i++)cout << srt[i] << " ";
    // cout << endl;
    nrm[srt[1]]=1;
    for(i=2;i<=n;i++)
    {
        if(ori[srt[i-1]] == ori[srt[i]])
        {
            nrm[srt[i]] = nrm[srt[i-1]];
        }
        else
        {
            nrm[srt[i]] = i;
        }
    }
    // cout << "d\n";
    // for(i=1;i<=n;i++)cout << nrm[i] << " ";
    // cout << endl;
    long long res = 0;
    for(i=n;i>=1;i--)
    {
        push_seg(1,500000,nrm[i]);
        // long long t = find_seg(1, 500000, nrm[i]-1);
        // cout << t << '\n';
        // res += t;
        res += find_seg(1, 500000, nrm[i]-1);
    }
    cout << res << '\n';
    return 0;
}