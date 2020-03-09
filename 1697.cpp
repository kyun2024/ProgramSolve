#include <iostream>
#include <queue>

using namespace std;

struct post{
    int origin,cnt;
};

int main(){
    int dp[200001]={0,};
    int dept,dest,ori,cnt;
    queue<post> q;
    cin >> dept >> dest;
    dp[dept]=1;
    q.push({dept,1});
    while(!q.empty() && q.front().origin!=dest){
        ori = q.front().origin;
        cnt = q.front().cnt;
        if(ori-1>=0 && !dp[ori-1]){
            dp[ori-1]=cnt+1;
            q.push({ori-1,cnt+1});
        }
        if(ori+1<=200000 && !dp[ori+1]){
            dp[ori+1]=cnt+1;
            q.push({ori+1,cnt+1});
        }
        if(2*ori<=200000 && !dp[ori*2]){
            dp[ori*2]=cnt+1;
            q.push({ori*2,cnt+1});
        }
        q.pop();
    }
    cout << dp[dest]-1 << endl;
    return 0;
}