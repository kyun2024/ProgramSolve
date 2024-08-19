#include <iostream>
#include <stack>

using namespace std;

int a[1001];
stack<int> st;

int main()
{
    int n, i, pos, c{};
    cin >> n;
    for(i=1;i<=n;++i)
    {
        cin >> a[i];
    }
    c = 1;
    for(i=1;i<=n;++i)
    {
        while(!st.empty() && st.top() == c)
        {
            ++c;
            st.pop();
        }
        if(a[i] == c)
        {
            ++c;
        }
        else
        {
            st.push(a[i]);
        }
    }
    while (!st.empty() && st.top() == c)
    {
        ++c;
        st.pop();
    }
    cout << (c > n?"Nice":"Sad") << endl;
    return 0;
}

// Wrong Code

// #include <iostream>

// using namespace std;

// int a[1001];
// int m[1001];

// int main()
// {
//     int n, i, c{};
//     cin >> n;
//     for(i=1;i<=n;++i)
//     {
//         cin >> a[i];
//     }
//     c = 1;
//     for(i=1;i<=n;++i)
//     {
//         if(a[i] == c)
//         {
//             m[c++]=c;
//         }
//     }
//     for(i=n;i>=1;--i)
//     {
//         if(a[i] == c)
//         {
//             m[c++] = c;
//         }
//     }
//     cout << (c > n?"Nice":"Sad") << endl;
//     return 0;
// }