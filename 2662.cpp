#include <iostream>

using namespace std;

int reward[21][301];
int invest[21][301];
int pst[21][301];

int asset, company;
bool found = false;

int dfs(int a, int n)
{
    int res = 0, tp = 0;
    int i, t;
    if (invest[n][a] != 0)
        return invest[n][a];
    if (n == 1)
        return reward[1][a];
    for (i = 0; i <= a; i++)
    {
        t = dfs(a - i, n - 1) + reward[n][i];
        if(res<t){
            res=t;
            tp=i;
        }
        res = max(res, t);
    }
    pst[n][a]=tp;
    return invest[n][a] = res;
}

void rec(int a, int n)
{
    if(n==0)return;
    rec(a-pst[n][a],n-1);
    cout << pst[n][a] << " ";
}

int main()
{
    int i, j, t;
    cin >> asset >> company;
    for (i = 1; i <= asset; i++)
    {
        cin >> t;
        for (j = 1; j <= company; j++)
        {
            cin >> reward[j][i];
        }
        invest[1][i]=reward[1][i];
        pst[1][i]=i;
    }
    cout << dfs(asset, company) << endl;
    /*
    for(i=0;i<=asset;i++){
        for(j=1;j<=company;j++){
            cout << invest[j][i] << " ";
        }
        cout << endl;
    }
    */
    rec(asset, company);
    cout << endl;
}