#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>

using namespace std;

int input_query[100000][3];
bitset<100001> visited;
long long node_diff[100001];
int parent_node[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int N, Q;
    int i;
    string in_str;
    vector<vector<pair<int,int>>> adj_list;
    while(1)
    {
        // Init
        adj_list.clear();
        visited.reset();
        // Input
        cin >> N >> Q;
        adj_list.resize(N+1);
        fill_n(node_diff, (N+1), 0);
        for(i=1;i<=N;i++)parent_node[i]=i;
        if(N == 0 && Q == 0)break;
        for(i=0;i<Q;i++)
        {
            cin.get();
            cin >> in_str;
            if(in_str == "!")
            {
                cin >> input_query[i][0] >> input_query[i][1] >> input_query[i][2];
                const int& sn1 = input_query[i][0], &sn2 = input_query[i][1], &diff = input_query[i][2];
                adj_list[sn1].push_back({sn2, diff});
                adj_list[sn2].push_back({sn1, -diff});
            } 
            else
            {
                input_query[i][0] = -1;
                cin >> input_query[i][1] >> input_query[i][2];
            }
        }
        // Proc
        // Step 1 : Make Tree and Set distance
        for(i=1;i<=N;i++)
        {
            if(!visited[i])
            {
                visited[i]=1;
                queue<pair<int,int>> que;
                que.push({i, 0});
                while(!que.empty())
                {
                    const int& node = que.front().first;
                    const int& dist = que.front().second;
                    node_diff[node]=dist;
                    for(const auto& nn : adj_list[node])
                    {
                        if(!visited[nn.first])
                        {
                            visited[nn.first]=1;
                            que.push({nn.first, dist + nn.second});
                        }
                    }
                    que.pop();
                }
            }
        }
        // Step 2 : Union and Query
        stack<int> st_a, st_b;
        for(i=0;i<Q;i++)
        {
            if(input_query[i][0] == -1)
            {
                // Query
                // if root_node is different then UNKNOWN
                // else print node_diff[input_query[i][2]]-node_diff[input_query[i][1]]
                int a = input_query[i][1];
                int b = input_query[i][2];
                int diff = node_diff[b]-node_diff[a];
                st_a.push(a); st_b.push(b);
                while(st_a.top() != parent_node[st_a.top()])st_a.push(parent_node[st_a.top()]);
                while(st_b.top() != parent_node[st_b.top()])st_b.push(parent_node[st_b.top()]);
                a = st_a.top(); b = st_b.top();
                if(a != b){
                    cout << "UNKNOWN" << "\n";
                }
                else
                {
                    cout << diff << "\n";
                }
                while(!st_a.empty()){ parent_node[st_a.top()] = a; st_a.pop();}
                while(!st_b.empty()){ parent_node[st_b.top()] = b; st_b.pop();}
            }
            else
            {
                // Union
                // set root
                const int& a = input_query[i][0];
                const int& b = input_query[i][1];
                st_a.push(a); st_b.push(b);
                while(st_a.top() != parent_node[st_a.top()])st_a.push(parent_node[st_a.top()]);
                while(st_b.top() != parent_node[st_b.top()])st_b.push(parent_node[st_b.top()]);
                const int& new_root_node = min(st_a.top(), st_b.top());
                while(!st_a.empty()){ parent_node[st_a.top()] = new_root_node; st_a.pop();}
                while(!st_b.empty()){ parent_node[st_b.top()] = new_root_node; st_b.pop();}
            }
        }
    }
    return 0;
}