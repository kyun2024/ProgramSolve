#include <iostream>
#include <stack>

using namespace std;

int p[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    int i;
    stack<int> st;

    cin >> n >> m;
    for (i = 0; i <= n; i++)
    {
        p[i] = i;
    }
    int a, b, c;
    int h1, h2;
    for (i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        if (a == 0)
        {
            st.push(b);
            while (p[st.top()] != st.top())
            {
                st.push(p[st.top()]);
            }
            h1 = st.top();
            while (!st.empty())
            {
                p[st.top()] = h1;
                st.pop();
            }

            st.push(c);
            while (p[st.top()] != st.top())
            {
                st.push(p[st.top()]);
            }
            h2 = st.top();
            while (!st.empty())
            {
                p[st.top()] = h2;
                st.pop();
            }
            if (h1 < h2)
            {
                p[h2] = h1;
            }
            else
            {
                p[h1] = h2;
            }
        }
        else
        {
            st.push(b);
            while (p[st.top()] != st.top())
            {
                st.push(p[st.top()]);
            }
            h1 = st.top();
            while (!st.empty())
            {
                p[st.top()] = h1;
                st.pop();
            }
            st.push(c);
            while (p[st.top()] != st.top())
            {
                st.push(p[st.top()]);
            }
            h2 = st.top();
            while (!st.empty())
            {
                p[st.top()] = h2;
                st.pop();
            }
            if (h1 == h2)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }
    return 0;
}