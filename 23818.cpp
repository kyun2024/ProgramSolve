#include <iostream>
#include <vector>
#include <bitset>
#include <stack>
#include <tuple>

using namespace std;

vector<vector<pair<int,int>>> adj_list;
int dist[100001];
int group_number[100001];
bitset<100001> error_group;
struct T_
{
    int t, a, b;
} r_m[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, R, Q;
    int i;
    int t, a, b;
    cin >> N >> R >> Q;
    adj_list.resize(N+1);
    for(i=0;i<R;i++)
    {
        cin >> t >> a >> b;
        r_m[i].t = t; r_m[i].a = a; r_m[i].b = b;
        adj_list[a].push_back({b, t});
        adj_list[b].push_back({a, t});
    }
    // for(i=1;i<=N;i++)
    // {
    //     cout << i << " : ";
    //     for(int j=0;j<adj_list[i].size();j++)cout<< "(" << adj_list[i][j].first << ", " << adj_list[i][j].second << ") ";
    //     cout << endl;
    // }
    {
        auto& visited = error_group;
        visited.reset();
        stack<tuple<int, int ,vector<pair<int,int>>::iterator>> st;
        for(i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                st.push(make_tuple(i, 0, adj_list[i].begin()));
                group_number[i]=i;
                dist[i] = 0;
                while(!st.empty())
                {
                    int cur_node = get<0>(st.top());
                    int cur_dist = get<1>(st.top());
                    // cout << "cur_node : " << cur_node << ", cur_dist : " << cur_dist << ", cur_idx : " << (int)(get<2>(st.top())-adj_list[cur_node].begin()) << endl;
                    for(auto it = get<2>(st.top()); it != adj_list[get<0>(st.top())].end(); ++it)
                    {
                        if(!visited[it->first])
                        {
                            visited[it->first]=1;
                            group_number[it->first]=i;
                            dist[it->first] = cur_dist + it->second;
                            st.pop();
                            st.push(make_tuple(cur_node, cur_dist, it+1));
                            st.push(make_tuple(it->first, (cur_dist + it->second)%2, adj_list[it->first].begin()));
                            st.push(make_tuple(0, 0, vector<pair<int,int>>::iterator{}));
                            break;
                        }
                    }
                    st.pop();
                }
            }
        }
        visited.reset();
    }
    for(const auto& edge : r_m)
    {
        if((dist[edge.a]+dist[edge.b])%2 != edge.t)
        {
            error_group[group_number[edge.a]]=1;
        }
    }
    for(i=0;i<Q;i++)
    {
        cin >> a >> b;
        if(group_number[a] != group_number[b])  cout << "Unknown" << "\n";
        else if(error_group[group_number[a]])   cout << "Error" << "\n";
        else if((dist[a]+dist[b])%2)            cout << "Enemy" << "\n";
        else                                    cout << "Friend" << "\n";
    }
    return 0;
}