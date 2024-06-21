#include <iostream>

using namespace std;

int N, Q;
int tree[200001];
int a[200001];

int sum(int i)
{
    int res = 0;
    for(;i>0;i -= (i&-i))
        res += tree[i];
    return res;
}

void add(int i, int num)
{
    if(!num)return;
    for(;i<=N;i += (i&-i))
        tree[i] += num;
}

void update(int i, int num)
{
    a[i]=num;
    // 그냥 코너케이스 다 처리하죠?
    if(i==1)
    {
        add(2, (a[1] != a[2])-(tree[2]-tree[1])); // only update i+1
    }
    else if(i==N)
    {
        add(N, (a[N-1] != a[N])-(sum(N)-sum(N-1))); // only update i
    }
    else
    {
        add(i, (a[i-1] != a[i])-(sum(i)-sum(i-1)));
        add(i+1, (a[i] != a[i+1])-(sum(i+1)-sum(i)));
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i;
    int i0, i1, i2;
    cin >> N >> Q;
    for(i=1;i<=N;++i)
    {
        cin >> i0;
        update(i, i0);
    }
    while(Q--)
    {
        cin >> i0 >> i1 >> i2;
        switch(i0)
        {
        case 1:
            update(i1, i2);
            break;
        case 2:
            cout << sum(i2)-sum(i1)+1 << '\n';
        }
    }
    return 0;
}