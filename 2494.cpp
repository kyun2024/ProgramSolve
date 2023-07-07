#include <iostream>
#include <string>
#include <memory.h>
#include <stack>

using namespace std;

int n;
string seq1, seq2;
int memo[10000][10];
int memo_rot[10000][10];
bool check[10000][10];

int main()
{
    int i,j;

    cin >> n;
    cin.get();
    getline(cin, seq1);
    getline(cin, seq2);

    int offset{}, rot{};
    offset = rot = (seq2[0]-seq1[0]+10)%10;
    memo[0][offset] = rot;
    memo_rot[0][offset] = rot;
    check[0][offset] = 1;

    rot = (seq1[0]-seq2[0]+10)%10;
    offset = 0;
    memo[0][offset] = rot;
    memo_rot[0][offset] = -rot;
    check[0][offset] = 1;

    // for (j = 0; j < 10; j++)
    // {
    //     cout << memo[0][j] << " ";
    // }
    // cout << endl;
    for(i=1;i<n;i++)
    {
        for(j=0;j<10;j++)
        {
            if(check[i-1][j])
            {
                rot = (seq2[i]-seq1[i]-j+20)%10;
                offset = (rot + j)%10;
                if(!check[i][offset] || check[i][offset] && memo[i][offset] > memo[i-1][j] + rot)
                {
                    check[i][offset]=1;
                    memo[i][offset] = memo[i-1][j] + rot;
                    memo_rot[i][offset] = rot;
                }
                rot = (seq1[i] - seq2[i] + j + 10)%10;
                offset = j;
                if(!check[i][offset] || check[i][offset] && memo[i][offset] > memo[i-1][j] + rot)
                {
                    check[i][offset] = 1;
                    memo[i][offset] = memo[i-1][j] + rot;
                    memo_rot[i][offset] = -rot;
                }
            }
        }
        // for(j=0;j<10;j++)
        // {
        //     cout << memo[i][j] << " ";
        // }
        // cout << endl;
    }
    int res = 987654321, min_i = -1;
    for(i=0;i<10;i++)
    {
        if(check[n-1][i] && memo[n-1][i] < res)
        {
            res = memo[n-1][i];
            min_i = i;
        }
    }
    cout << res << '\n';

    stack<pair<int,int>> st;
    j = min_i;
    for(i = n-1;i>=0;i--)
    {
        //cout << i+1 << " " << j << " " << memo_rot[i][j] << '\n';
        if(memo_rot[i][j]!=0)
        {
            st.push({i+1,memo_rot[i][j]});
        }
        j = (j-max(memo_rot[i][j],0)+10)%10;
    }
    while(!st.empty())
    {
        cout << st.top().first << " " << st.top().second << '\n';
        st.pop();
    }
    return 0;
}