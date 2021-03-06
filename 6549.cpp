#include <iostream>
#include <stack>

using namespace std;

struct stt
{
    long long v, c;
};

int subprogram(){
    long long res = 0;
    stack<stt> s;
    int n, i, c, x;
    cin >> n;
    if(n==0)return 0;
    for (i = 1; i <= n; i++)
    {
        cin >> x;
        c = 0;
        while (!s.empty() && x <= s.top().v)
        {
            stt cr = s.top();
            c += cr.c;
            res = max(res, cr.v * c);
            s.pop();
        }
        s.push(stt({x, c + 1}));
    }
    c = 0;
    while (!s.empty())
    {
        stt cr = s.top();
        c += cr.c;
        res = max(res, cr.v * c);
        s.pop();
    }
    cout << res << endl;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    while(subprogram());
    return 0;
}