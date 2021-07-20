#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;

int v[101];

int main()
{
    int pm, n;
    cin >> pm >> n;
    int i;
    for (i = 1; i <= pm; i++)
        cin >> v[i];
    for (i = 1; i <= pm; i++)
        pq.push(v[i]);
    n--;
    while (n--)
    {
        long long x = pq.top();
        //cout << x << endl;
        pq.pop();
        for (i = pm; i >= 1; i--)
        {
            long long t = v[i] * x;
            if (t < (1U << 31))
                pq.push(t);
            if(x % v[i] == 0)break;
        }
    }
    cout << pq.top() << endl;
    return 0;
}