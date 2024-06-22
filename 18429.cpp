#include <iostream>

using namespace std;

int N, K;

bool check[8];
int add_w[8];

int dfs(int w, int d)
{
    if(w<0)return 0;
    if(d==N)
    {
        return w>=0;
    }
    int s=0;
    for(int i=0;i<N;i++)
    {
        if(!check[i])
        {
            check[i]=1;
            s += dfs(w+add_w[i]-K, d+1);
            check[i]=0;
        }
    }
    return s;
}

int main()
{
    cin >> N >> K;
    for(int i=0;i<N;i++)
    {
        cin >> add_w[i];
    }
    cout << dfs(0, 0) << endl;
    return 0;
}