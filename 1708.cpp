#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

using ll = long long;
using CT = array<ll, 2>;

CT C[100000];
vector<CT> st, st_lw;

ll ccw(CT _0, CT _1, CT _2)
{
    auto &[x0, y0] = _0; auto &[x1, y1] = _1; auto &[x2, y2] = _2;
    return (x1 - x0) * (y2 - y0) - (x2 - x0) * (y1 - y0);
}

int main()
{
    int N;
    int i;
    cin >> N;
    for(i=0;i<N;++i)
    {
        auto &[x, y] = C[i];
        cin >> x >> y;
    }
    // upper line
    sort(C, C+N, [](const CT& i, const CT& j){
        if(i[0] == j[0])
        {
            return i[1] > j[1];
        }
        return i[0] < j[0];
    });

    st.push_back(C[0]); st.push_back(C[1]);
    for(i=2;i<N;++i)
    {
        while(st.size()>=2 && ccw(st.end()[-2], st.end()[-1], C[i])>=0)st.pop_back();
        st.push_back(C[i]);
    }

    // lower line
    sort(C, C+N, [](const CT& i, const CT& j){
        if(i[0] == j[0])return i[1] < j[1];
        return i[0] < j[0];
    });

    st_lw.push_back(C[0]); st_lw.push_back(C[1]);
    for(i=2;i<N;++i)
    {
        while(st_lw.size()>=2 && ccw(st_lw.end()[-2], st_lw.end()[-1], C[i])<=0)st_lw.pop_back();
        st_lw.push_back(C[i]);
    }
    
    st.insert(st.end(), st_lw.begin(), st_lw.end());
    sort(st.begin(), st.end());
    st.erase(unique(st.begin(), st.end()), st.end());
    
    cout << st.size() << endl;
    return 0;
}