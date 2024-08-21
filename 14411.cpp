#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

pair<long long, long long> rects[1000001];
stack<pair<long long,long long>> st;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    int N;
    int i;
    cin >> N;
    for(i=0;i<N;++i)cin >> rects[i].first >> rects[i].second;
    sort(rects, rects+N, [](const pair<long long,long long>& i, const pair<long long,long long>& j){
        if(i.first == j.first)
        {
            return i.second > j.second;
        }
        return i.first > j.first;
    });
    st.push(rects[0]);
    for(i=1;i<N;++i)
    {
        if(rects[i].first < st.top().first && rects[i].second > st.top().second)st.push(rects[i]);
    }
    pair<long long,long long> last_top = st.top();
    st.pop();
    long long res = last_top.first * last_top.second;
    while(!st.empty())
    {
        res += (st.top().first - last_top.first) * st.top().second;
        last_top = st.top();
        st.pop();
    }
    cout << res << endl;
    return 0;
}