#include <bits/stdc++.h>

#define loop while(1)

using namespace std;

vector<vector<pair<int, int>>> adj_list;
bitset<100001> visited;

int ancestor_map[17][100001];
long long distance_mmap[17][100001];
long long distance_Mmap[17][100001];
int depth_map[100001];
int N;

void visit_neighbors(int node, int depth)
{
    // cout << "Debug|visit_neighbors| " << node << " " << depth << endl;
    visited[node] = 1;
    depth_map[node] = depth;
    for(auto neighbor : adj_list[node])
    {
        if(!visited[neighbor.first])
        {
            ancestor_map[0][neighbor.first] = node;
            distance_mmap[0][neighbor.first] = neighbor.second;
            distance_Mmap[0][neighbor.first] = neighbor.second;
            for(int i=1; depth + 1 - (1<<i) > 0; ++i)
            {
                ancestor_map[i][neighbor.first] = ancestor_map[i-1][ancestor_map[i-1][neighbor.first]];
                distance_mmap[i][neighbor.first] = min(distance_mmap[i-1][ancestor_map[i-1][neighbor.first]], distance_mmap[i-1][neighbor.first]);
                distance_Mmap[i][neighbor.first] = max(distance_Mmap[i-1][ancestor_map[i-1][neighbor.first]], distance_Mmap[i-1][neighbor.first]);
                // cout << "Debug|visit_neighbors| " << i << ", " << neighbor.first << " -> " << ancestor_map[i][neighbor.first] << endl;
                // cout << "Debug|visit_neighbors| " << i << ", " << neighbor.first << " -> " << distance_map[i][neighbor.first] << endl;
            }
            visit_neighbors(neighbor.first, depth+1);
        }
    }
}

void init_map()
{
    visit_neighbors(1, 1);
}

pair<long long, long long> distance_node(int na, int nb)
{
    // cout << "Debug| " << na << ", " << nb << ", " << 0 << endl;
    // cout << "Debug| " << depth_map[na] << ", " << depth_map[nb] << endl;
    int i;
    long long res_min=1e12, res_max = 0;
    if(depth_map[na] < depth_map[nb])swap(na, nb);
    int depth_diff = depth_map[na]-depth_map[nb];
    for(i=0; depth_diff; ++i, depth_diff >>= 1)
    {
        if(depth_diff & 1) { 
            res_min = min(res_min, distance_mmap[i][na]);
            res_max = max(res_max, distance_Mmap[i][na]);
            na = ancestor_map[i][na];
        }
    }
    if(na == nb)return {res_min, res_max};
    // cout << "Debug| " << na << ", " << nb << ", " << res << endl;
    loop {
        if(ancestor_map[0][na] == ancestor_map[0][nb])
        {
            res_min = min(min(res_min, distance_mmap[0][na]), distance_mmap[0][nb]);
            res_max = max(max(res_max, distance_Mmap[0][na]), distance_Mmap[0][nb]);
            break;
        }
        int aa, ab; i=1;
        loop {
            aa = ancestor_map[i][na]; ab = ancestor_map[i][nb];
            if(aa == ab)break;
            ++i;
        }
        res_min = min(min(res_min, distance_mmap[i-1][na]), distance_mmap[i-1][nb]);
        res_max = max(max(res_max, distance_Mmap[i-1][na]), distance_Mmap[i-1][nb]);
        na = ancestor_map[i-1][na]; nb = ancestor_map[i-1][nb];
        // cout << "Debug| " << na << ", " << nb << ", " << res << endl;
    }
    // cout << "Debug| " << na << ", " << nb << ", " << res << endl;
    return {res_min, res_max};
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i, a, b, w;
    int Q;
    cin >> N;
    adj_list.resize(N+1);
    for(i=1;i<N;++i)
    {
        cin >> a >> b >> w;
        adj_list[a].push_back(make_pair(b, w));
        adj_list[b].push_back(make_pair(a, w));
    }
    init_map();
    cin >> Q;
    while(Q--)
    {
        cin >> a >> b;
        auto res = distance_node(a,b);
        cout << res.first << " " << res.second << '\n';
    }
    return 0;
}