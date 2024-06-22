#include <iostream>
#include <queue>

using namespace std;

int shortest_p[500001][2];
bool check[500001][2];
queue<pair<int,int>> que;

int main()
{
    bool found = false;
    int N, K;
    int i;
    cin >> N >> K;
    que.push({N, 0});
    check[N][0] = 1;
    while(!que.empty())
    {
        int pos = que.front().first;
        int t = que.front().second;
        if(pos <= 250000 && !check[pos*2][(t+1)%2])
        {
            check[pos*2][(t+1)%2] = 1;
            shortest_p[pos*2][(t+1)%2] = t+1;
            que.push({pos * 2, t+1});
        }
        if(pos < 500000 && !check[pos+1][(t+1)%2])
        {
            check[pos+1][(t+1)%2] = 1;
            shortest_p[pos+1][(t+1)%2] = t+1;
            que.push({pos + 1, t+1});
        }
        if(pos>0 && !check[pos-1][(t+1)%2])
        {
            check[pos-1][(t+1)%2] = 1;
            shortest_p[pos-1][(t+1)%2] = t+1;
            que.push({pos-1, t+1});
        }
        que.pop();
    }
    int k;
    int min_time = 987654321;
    for(i=0, k=K; k<=500000; k += ++i)
    {
        if(check[k][0] && shortest_p[k][0] <= i && (shortest_p[k][0]%2) == (i%2))
        {
            min_time = i;
            break;
        }
        if(check[k][1] && shortest_p[k][1] <= i && (shortest_p[k][1]%2) == (i%2))
        {
            min_time = i;
            break;
        }
    }
    if(min_time != 987654321)
    {
        cout << min_time << endl;
    }
    else cout << -1 << endl;
    return 0;
}