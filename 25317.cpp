#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

using ll = long long;

vector<tuple<long long, long long, long long>> queries;
vector<ll> sol;
map<ll, bool> z_check;
map<ll, int> indexer;

int N;

class BITree
{
public:
    vector<int> fwt;

public:
    BITree(int n)
    {
        fwt.assign(n + 1, 0);
    }
    int sum(int i)
    {
        int res = 0;
        while (i > 0)
        {
            res += fwt[i];
            i -= (i & -i);
        }
        return res;
    }
    void add(int i, int num)
    {
        while (i < fwt.size())
        {
            fwt[i] += num;
            i += (i & -i);
        }
    }
    int range_sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }
};

ll get_sol(ll a, ll b)
{
    if (a < 0 != b < 0) return a/b;
    return a/b + (a%b?1:0);
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i, j;
    ll q0, q1, q2;
    int Q;
    cin >> Q;
    for (i = 0; i < Q; ++i)
    {
        cin >> q0 >> q1;
        if (q0 == 1)
            cin >> q2;
        switch (q0)
        {
        case 1:
            queries.push_back({q0, q1, q2});
            if (q1 == 0)
            {
                // do nothing
            }
            else if (abs(q2) % abs(q1) == 0ll)
            {
                // z_check[-q2 / q1] = 1;
                sol.push_back(-q2 / q1);
            }
            else
            {
                sol.push_back(get_sol(-q2, q1));
            }
            break;
        case 2:
            queries.push_back({q0, q1, 0});
            sol.push_back(q1);
            break;
        }
    }
    // for(auto x : sol){ cout << x << " ";} cout << endl;
    
    sort(sol.begin(), sol.end());
    sol.erase(unique(sol.begin(), sol.end()), sol.end());

    // for(auto x : sol){ cout << x << " ";} cout << endl;

    for (i = 0; i < sol.size(); ++i)
    {
        indexer[sol[i]] = i + 1;
    }

    BITree h_tree{sol.size()};
    int sign = 1;

    for (i = 0; i < Q; ++i)
    {
        if (get<0>(queries[i]) == 1)
        {
            auto [_, a, b] = queries[i];
            if (a != 0 && abs(b) % abs(a) == 0ll)
            {
                z_check[-b / a] = 1;
            }
            if (a > 0)
            {
                h_tree.add(indexer[get_sol(-b, a)], 1);
            }
            else if (a < 0)
            {
                h_tree.add(indexer[get_sol(b, -a)], 1);
                sign *= -1;
            }
            else
            {
                if (b == 0)sign = 0;
                else if(b<0)sign *= -1;
            }
        }
        else
        {
            long long x = get<1>(queries[i]);
            if (z_check.find(x) != z_check.end() || sign == 0)
            {
                cout << 0 << '\n';
                continue;
            }
            int h_sign;
            int idx = indexer[x];

            if (idx == sol.size())
            {
                h_sign = 1;
            }
            else
                h_sign = -2 * (h_tree.range_sum(idx + 1, sol.size()) % 2) + 1;

            int tot_sign = h_sign * sign;
            const char s[] = "-0+";
            cout << s[tot_sign + 1] << '\n';
        }
    }
    return 0;
}