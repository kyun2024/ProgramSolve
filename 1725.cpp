#include <iostream>
#include <vector>

using namespace std;

struct ds
{
public:
    ds(int h=0,int id=0):h(h),id(id){}
    int h, id;
};

int a[100001];

int main()
{
    int res = 0;
    int n;
    int i, j;
    ds t;
    vector<ds> s;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    s.reserve(n + 1);
    s.push_back({0, 0}); //dummy
    for (i = 1; i <= n; i++)
    {
        while (s.size() > 1 && s.back().h >= a[i])
        {
            t = s.back();
            s.pop_back();
            res = max(res, t.h * (t.id - s.back().id));
            if(s.back().h>a[i])s.back().id=t.id;
        }
        if(a[i]!=0)s.push_back(ds(a[i], i));
        else{
            s[0].id=i;
        }
        if (true)
        {
            for (j = 1; j < s.size(); j++)
            {
                cout << s[j].h << "(" << s[j].id << ") ";
            }
            cout << endl;
        }
    }
    while (s.size() > 1)
    {
        t = s.back();
        s.pop_back();
        res = max(res, t.h * (t.id - s.back().id));
        s.back().id = t.id;
    }
    cout << res << endl;
    return 0;
}