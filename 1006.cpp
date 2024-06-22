#include <bits/stdc++.h>

using namespace std;

int aA[10000][2];
int memo[10000][3];
int N, W;

inline void clear_memo()
{
    for(int i=0;i<N;++i)
    {
        memo[i][0] = memo[i][1] = memo[i][2] = 0;
    }
}

int min_wo0a(int a,int b)
{
    if(a)return min(a,b);
    else return b;
}

void sol()
{
    for(int i=1;i<N;++i)
    {
        if(memo[i-1][2])                            memo[i][0] = min_wo0a(memo[i][0], memo[i-1][2]+1);
        if(memo[i-1][1] && aA[i-1][0]+aA[i][0]<=W)  memo[i][0] = min_wo0a(memo[i][0], memo[i-1][1]+1);
        if(memo[i-1][2])                            memo[i][1] = min_wo0a(memo[i][1], memo[i-1][2]+1);
        if(memo[i-1][0] && aA[i-1][1]+aA[i][1]<=W)  memo[i][1] = min_wo0a(memo[i][1], memo[i-1][0]+1);
        if(memo[i][0])                              memo[i][2] = min_wo0a(memo[i][2], memo[i][0]+1);
        if(memo[i][1])                              memo[i][2] = min_wo0a(memo[i][2], memo[i][1]+1);
        if(memo[i-1][2])                            memo[i][2] = min_wo0a(memo[i][2], memo[i-1][2]+2);
        if(memo[i-1][2] && aA[i][0]+aA[i][1]<=W)    memo[i][2] = min_wo0a(memo[i][2], memo[i-1][2]+1);
        if(i>=2 && memo[i-2][2] && 
        (aA[i-1][0]+aA[i][0] <= W && aA[i-1][1]+aA[i][1] <= W ||
         aA[i-1][0]+aA[i-1][1] <= W && aA[i][0]+aA[i][1] <= W))
            memo[i][2] = min_wo0a(memo[i][2], memo[i-2][2]+2);
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int T;
    cin >> T;

    int i;
    while(T--)
    {
        cin >> N >> W;
        for(i=0;i<N;++i)cin >> aA[i][0];
        for(i=0;i<N;++i)cin >> aA[i][1];

        int res = 100000;
        // 예외처리 - N<=2
        if(N==1)
        {
            if(aA[0][0]+aA[0][1]<=W)res=1;
            else res=2;
            cout << res << '\n';
            continue;
        }
        else if(N==2)
        {
            if(aA[0][0]+aA[1][0]<=W&&aA[0][1]+aA[1][1]<=W||aA[0][0]+aA[0][1]<=W&&aA[1][0]+aA[1][1]<=W)res=2;
            else if(aA[0][0]+aA[1][0]<=W||aA[0][1]+aA[1][1]<=W||aA[0][0]+aA[0][1]<=W||aA[1][0]+aA[1][1]<=W)res=3;
            else res=4;
            cout << res << '\n';
            continue;
        }

        // 10개의 경우에 대해 전부 탐색
        
        
        // Case 1 - 처음 1칸을 위아래로 채우고 탐색하는 경우 (1개 팀 필요)
        if(aA[0][0] + aA[0][1] <= W)
        {
            clear_memo();
            memo[0][2]=1;
            sol();
            res = min(res,memo[N-1][2]);
            // cout << "C1 : " << memo[N-1][2] << '\n';
        } // Case 2 - 처음 1칸을 위아래로 채우고 탐색하는 경우 (2개 팀 필요)
        else 
        {
            clear_memo();
            memo[0][2]=2;
            sol();
            res = min(res,memo[N-1][2]);
            // cout << "C2 : " << memo[N-1][2] << '\n';
        }
        // Case 3 - 1+2 배열, 2-1
        if(aA[0][0]+aA[1][0] <= W)
        {
            clear_memo();
            memo[1][0] = 2;
            sol();
            res = min(res,memo[N-1][2]);
            // cout << "C3 : " << memo[N-1][2] << '\n';
        }
        // Case 4 - 1+2 배열, 1-2
        if(aA[0][1]+aA[1][1] <= W)
        {
            clear_memo();
            memo[1][1] = 2;
            sol();
            res = min(res,memo[N-1][2]);
            // cout << "C4 : " << memo[N-1][2] << '\n';
        }
        // Case 5 - 1+2 배열, (0)1-1
        if(aA[N-1][0]+aA[0][0]<=W)
        {
            clear_memo();
            memo[0][2] = 2;
            sol();
            res = min(res, memo[N-1][1]);
            // cout << "C5 : " << memo[N-1][1] << '\n';
        }
        // Case 6 - 1+2 배열, 1-(0)1
        if(aA[N-1][1]+aA[0][1] <= W)
        {
            clear_memo();
            memo[0][2] = 2;
            sol();
            res = min(res, memo[N-1][0]);
            // cout << "C6 : " << memo[N-1][0] << '\n';
        }
        // Case 7 - 2+2 배열, 2-2
        if(aA[0][0]+aA[1][0]<=W && aA[0][1]+aA[1][1]<=W)
        {
            clear_memo();
            memo[1][0] = memo[1][1] = memo[1][2] = 2;
            sol();
            res = min(res, memo[N-1][2]);
            // cout << "C7 : " << memo[N-1][2] << '\n';
        }
        // Case 8 - 2+2 배열, (0)1-(0)1
        if(aA[N-1][0]+aA[0][0]<=W && aA[N-1][1]+aA[0][1] <= W)
        {
            clear_memo();
            memo[0][2] = 2;
            sol();
            res = min(res, memo[N-2][2]);
            // cout << "C8 : " << memo[N-2][2] << '\n';
        }
        // Case 9 - 2+2 배열, 2-(0)1
        if(aA[0][0]+aA[1][0]<=W && aA[N-1][1]+aA[0][1]<=W)
        {
            clear_memo();
            memo[1][0] = 2;
            sol();
            res = min(res, memo[N-1][0]);
            // cout << "C9 : " << memo[N-1][0] << '\n';
        }
        // Case 10 - 2+2 배열, (0)1-2
        if(aA[N-1][0]+aA[0][0]<=W && aA[0][1]+aA[1][1]<=W)
        {
            clear_memo();
            memo[1][1] = 2;
            sol();
            res = min(res, memo[N-1][1]);
            // cout << "C10 : " << memo[N-1][1] << '\n';
        }
        cout << res << '\n';
    }
    return 0;
}