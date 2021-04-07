#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adj_list;

bool visited[100001];

pair<int,int> dfs(int n)
{
    int s_max = 0, d;
    pair<int,int> df;
    int res = 0;
    int sub_res = 0;
    visited[n] = true;
    for (auto x : adj_list[n])
    {
        if (!visited[x.first])
        {
            df = dfs(x.first);
            d = df.first + x.second;
            if (res <= d)
            {
                s_max = res;
                res = d;
            }
            else if(s_max<d){
                s_max = d;
            }
            sub_res = max(sub_res,df.second);
        }
    }
    if(sub_res < res+s_max){
        sub_res = res+s_max;
    }
    return make_pair(res,sub_res);
}

int main()
{
    int n;
    int i, org, dest, weight;
    cin >> n;
    adj_list.resize(n + 1);
    for (i = 1; i < n; i++)
    {
        cin >> org >> dest >> weight;
        adj_list[org].push_back(make_pair(dest,weight));
        adj_list[dest].push_back(make_pair(org,weight));
    }
    cout << dfs(n).second << endl;
    return 0;
}