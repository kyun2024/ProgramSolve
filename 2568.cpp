#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> ps[100001];
int mem[100001];
vector<int> sl;
bool check[100001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int i;
    cin >> n;
    sl.reserve(n);
    for(i=1;i<=n;i++)
    {
        cin >> ps[i].first >> ps[i].second;
    }
    sort(ps+1, ps+n+1, [](const pair<int,int>& i, const pair<int,int> &j){
        return i.first < j.first;
    });
    // cout << "sort res : " << '\n';
    // for(i=1;i<=n;i++)cout << ps[i].first << " " << ps[i].second << endl;
    mem[1] = 1;
    sl.push_back(ps[1].second);
    for(i=2;i<=n;i++)
    {
        auto pos = lower_bound(sl.begin(),sl.end(),ps[i].second);
        // cout << "lower bound of " << ps[i].second << " : " << (pos-sl.begin()) << endl;
        if(pos == sl.end())
        {
            sl.push_back(ps[i].second);
            mem[i] = sl.size();
        }
        else
        {
            *pos = ps[i].second;
            mem[i] = pos-sl.begin()+1;
        }
    }
    int level = sl.size();
    int under_k = 999999;
    for(i=n;i>=1 && level > 0;i--)
    {
        if(mem[i] == level && ps[i].second < under_k)
        {
            --level;
            under_k = ps[i].second;
            check[i] = 1;
        }
    }
    cout << n-sl.size() << '\n';
    for(i=1;i<=n;i++){
        if(!check[i])cout << ps[i].first << '\n';
    }
    return 0;
}