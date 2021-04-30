#include <iostream>
#include <list>
#include <queue>

using namespace std;

int check[20001];
list<int> adj[20001];

void procedure1()
{

    int n, m;
    int i;
    int a, b;
    cin >> n >> m;
    //init
    for (i = 1; i <= n; i++)
    {
        check[i] = 0;
        adj[i].clear();
    }
    for (i = 0; i < m; i++)
    {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int> q;
    for (i = 1; i <= n; i++)
    {
        if (check[i] == 0)
        {
            q = queue<int>();
            q.push(i);
            check[i] = 1;
            int idx, bt;
            while (!q.empty())
            {
                idx = q.front();
                bt = !(check[idx] - 1) + 1;
                q.pop();
                for (int next : adj[idx])
                {
                    if (check[next] == 0)
                    {
                        check[next] = bt;
                        q.push(next);
                    }
                    else if (check[next] == check[idx])
                    {
                        cout << "NO" << endl;
                        return;
                    }
                }
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        procedure1();
    }
}