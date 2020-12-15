#include <iostream>
#include <list>
#include <stack>

using namespace std;

list<int> link[100001];
int point[100001];
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    int i, j, l;
    cin >> n >> k;
    cin >> j;
    for (i = 2; i <= n; i++)
    {
        cin >> j;
        link[j].push_back(i);
    }
    for (i = 1; i <= k; i++)
    {
        cin >> j >> l;
        point[j] += l;
    }
    list<int>::iterator it;
    st.push(1);
    while (!st.empty())
    {
        int p = st.top();
        st.pop();
        for (it = link[p].begin(); it != link[p].end(); it++)
        {
            point[*it] += point[p];
            st.push(*it);
        }
    }
    for(i=1;i<=n;i++){
        cout << point[i] << " ";
    }
    cout << "\n";
    return 0;
}