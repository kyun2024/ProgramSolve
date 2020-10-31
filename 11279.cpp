#include <queue>
#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int> pq;
    int n, m;
    cin >> n;
    while (n--)
    {
        cin >> m;
        if (m == 0)
        {
            if (pq.size() == 0)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(m);
        }
    }
}