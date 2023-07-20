#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> adj_list;

bool visited[250001];
int order[250001];

vector<vector<int>> query_list;

int order_n;

int initial_head[250001];
int head[250001];
long long weight[250001];
bool check[250001];

void dfs(int node, int parent)
{
    visited[node] = 1;
    order[node] = ++order_n;
    initial_head[node]=parent;
    for (auto nn : adj_list[node])
    {
        if (!visited[nn])
        {
            dfs(nn, node);
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, Q;
    int i, j, u, v;
    cin >> N;
    adj_list.resize(N + 1);
    for (i = 0; i < N - 1; ++i)
    {
        cin >> u >> v;
        adj_list[v].push_back(u);
        adj_list[u].push_back(v);
    }
    cin >> Q;
    int s;
    int n_input_list{};
    query_list.resize(Q);
    for (i = 0; i < Q; ++i)
    {
        cin >> s;
        for (j = 0; j < s; j++)
        {
            cin >> u;
            query_list[i].push_back(u);
        }
    }
    dfs(1, 1);
    for (i = 0; i < Q; i++)
    {
        const auto& q_list = query_list[i];
        sort(query_list[i].begin(), query_list[i].end(), [](const int &a0, const int &a1){
            return order[a0] > order[a1];
        });
        for(j=0;j<q_list.size();j++)check[q_list[j]]=1;
        for(j=0;j<q_list.size();j++)
        {
            if(check[initial_head[q_list[j]]])
                head[q_list[j]] = initial_head[q_list[j]];
            else
                head[q_list[j]] = q_list[j];
            weight[q_list[j]] = 1;
        }
        for(j=0;j<q_list.size();++j)
        {
            const int& c = q_list[j];
            if(head[c] != c)
            {
                weight[head[c]] += weight[c];
            }
        }
        long long res = 0;
        for(j=0;j<q_list.size();++j)
        {
            const int& c = q_list[j];
            if(head[c] == c)
            {
                res += (weight[c]-1)*weight[c] / 2;
            }
        }
        for(j=0;j<q_list.size();j++)check[q_list[j]]=0;
        cout << res << '\n';
    }
    
    return 0;
}