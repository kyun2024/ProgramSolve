#include <iostream>
#include <map>
#include <string>
#include <array>
#include <stack>

using namespace std;

using arr_i32 = array<int,200001>;

int uf_union(arr_i32& uf_m, arr_i32& c_m, int a, int b)
{
    stack<int> s_a, s_b;
    s_a.push(a); s_b.push(b);
    while(s_a.top() != uf_m[s_a.top()])s_a.push(uf_m[s_a.top()]);
    while(s_b.top() != uf_m[s_b.top()])s_b.push(uf_m[s_b.top()]);
    int min_v = min(s_a.top(),s_b.top());
    int sum_v = c_m[s_a.top()] + c_m[s_b.top()];
    // cout << "root of " << a << ", " << b << " : " << s_a.top() << ", " << s_b.top() << endl;
    // cout << "set size : " << c_m[s_a.top()] << " " << c_m[s_b.top()] << endl;
    if(s_a.top() == s_b.top())
    {
        return c_m[s_a.top()];
    }
    while(!s_a.empty())
    {
        uf_m[s_a.top()] = min_v;
        c_m[s_a.top()] = sum_v;
        s_a.pop();
    }
    while(!s_b.empty())
    {
        uf_m[s_b.top()] = min_v;
        c_m[s_b.top()] = sum_v;
        s_b.pop();
    }
    return sum_v;
}

void proc()
{
    int F;
    map<string, int> name_mapper;
    arr_i32 uf_m, c_m;
    int i;
    string str1, str2;

    cin >> F;
    for(i=0;i<2*F;i++)
    {
        uf_m[i]=i;
        c_m[i]=1;
    }

    cin.get();
    for(i=0;i<F;i++)
    {
        cin >> str1 >> str2;
        cin.get();
        // cout << "input names : " << str1 << ", " << str2 << endl; 
        int hv1, hv2;
        if(name_mapper.find(str1) == name_mapper.end())name_mapper[str1]=name_mapper.size();
        if(name_mapper.find(str2) == name_mapper.end())name_mapper[str2]=name_mapper.size();
        hv1 = name_mapper[str1];
        hv2 = name_mapper[str2];
        // cout << hv1 << " " << hv2 << endl;
        cout << uf_union(uf_m, c_m, hv1, hv2) << '\n';
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--)proc();
    return 0;
}