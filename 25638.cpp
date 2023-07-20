#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <tuple>

using namespace std;

int N;

int node_color[100001][2];
vector<vector<int>> adj_list;
bitset<100001> visited;
int head[100001];

long long memo[100001][2];
long long res_t[100001][2];

long long res_c[100001];

stack<tuple<int, int, int>> st; 

void dfs(int node, int parent)
{
    int idx;
    st.push(make_tuple(node, parent, 0));
    while(!st.empty())
    {
        node = get<0>(st.top());
        parent = get<1>(st.top());
        idx = get<2>(st.top());
        if(idx == 0)
        {
            visited[node] = 1;
            head[node] = parent;
            memo[node][0] = node_color[node][0];
            memo[node][1] = node_color[node][1];
        }
        else
        {
            memo[node][0] += memo[adj_list[node][idx-1]][0];
            memo[node][1] += memo[adj_list[node][idx-1]][1];
        }
        while(idx < adj_list[node].size())
        {
            if(!visited[adj_list[node][idx]])
            {
                get<2>(st.top()) = idx+1;
                st.push({adj_list[node][idx], node, 0});
                break;
            }
            else ++idx;
        }
        if(idx == adj_list[node].size())st.pop();
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    int i, c, a, b;
    cin >> N;
    for (i = 1; i <= N; ++i)
    {
        cin >> c;
        ++node_color[i][c];
    }
    adj_list.resize(N + 1);
    for (i = 1; i < N; i++)
    {
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    dfs(1, 1);
    int Q, n_nn;
    long long res;
    cin >> Q;
    while (Q--)
    {
        res = 0;
        n_nn = 0;
        cin >> c;
        if (visited[c])
        {
            res_t[adj_list[c].size()][0] = res_t[adj_list[c].size()][1] = 0;
            for (auto nn : adj_list[c])
            {
                if (head[c] == nn)
                {
                    res_t[n_nn][0] = (memo[1][0] - memo[c][0]);
                    res_t[n_nn][1] = (memo[1][1] - memo[c][1]);
                }
                else
                {
                    res_t[n_nn][0] = memo[nn][0];
                    res_t[n_nn][1] = memo[nn][1];
                }
                res_t[adj_list[c].size()][0] += res_t[n_nn][0];
                res_t[adj_list[c].size()][1] += res_t[n_nn][1];
                ++n_nn;
            }
            for (i = 0; i < n_nn; i++)
            {
                res += (res_t[i][0]) * (res_t[n_nn][1] - res_t[i][1]);
                res += (res_t[n_nn][0] - res_t[i][0]) * (res_t[i][1]);
            }
            cout << res / 2 << '\n';
            visited[c]=0;
            res_c[c] = res/2;
        }
        else
        {
            cout << res_c[c] << '\n';
        }
    }
}