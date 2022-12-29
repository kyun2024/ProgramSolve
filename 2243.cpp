#include <iostream>
#include <stack>

using namespace std;

int c[4000000];

void modify(int s, int e, int n, int diff)
{
    stack<int> s_n;
    int node = 1;
    int m;
    s_n.push(1);
    while(s<e)
    {
        m = (s+e)>>1;
        // partition 1 = 1..m
        // partition 2 = m+1..e
        if(m>=n)
        {
            e = m;
            node = 2*node;
        }
        else
        {
            s = m+1;
            node = 2*node + 1;
        }
        s_n.push(node);
    }
    while(!s_n.empty())
    {
        c[s_n.top()] += diff;
        s_n.pop();
    }
}

int modify_search(int s,int e,int nth)
{
    int node = 1;
    int m;
    stack<int> s_node;
    s_node.push(1);
    while(s<e)
    {
        m = (s+e)/2;
        if(c[2*node]>=nth)
        {
            node = 2*node;
            e = m;
        }
        else
        {
            nth -= c[2*node];
            node = 2*node+1;
            s = m + 1;
        }
        s_node.push(node);
    }
    while(!s_node.empty())
    {
        c[s_node.top()]--;
        s_node.pop();
    }
    return s;
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int a,b,c;
    int i;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> a;
        if(a==1)
        {
            cin >> b;
            cout << modify_search(1,1000000,b) << '\n';
        }
        else
        {
            cin >> b >> c;
            modify(1,1000000,b,c);
        }
    }
    return 0;
}