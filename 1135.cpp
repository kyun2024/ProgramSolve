#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int mp[50][50];
int v[50],tp[50],dp[50];

int main(){
    int n;
    int i,j;
    queue<int> q;

    cin >> n;
    cin >> v[0];
    for(i=1;i<n;i++){
        cin >> v[i];
        mp[v[i]][tp[v[i]]]=i;
        tp[v[i]]++;
    }
    for(i=0;i<n;i++){
        if(tp[i]==0){
            q.push(i);
            tp[i]--;
        }
    }
    while(!q.empty()){
        i=q.front();
        tp[v[i]]--;
        sort(mp[i],mp[i]+50,[](const int& i,const int& j){
            if(i==0){
                return false;
            }
            if(j==0){
                return true;
            }
            return dp[i]>dp[j];
        });
        for(j=0;mp[i][j]!=0;j++){
            dp[i]=max(dp[i],dp[mp[i][j]]+j+1);
        }
        for(j=0;j<n;j++){
            if(tp[j]==0){
                q.push(j);
                tp[j]--;
            }
        }
        q.pop();
    }
    cout << dp[0] << endl;
    return 0;
}