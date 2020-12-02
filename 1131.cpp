#include <iostream>
#include <cmath>

using namespace std;

int m[1000001];
bool check[1000001];
int a, b, k;

int get_next_n(int n)
{
    int num,t;
    num = 0;
    while (n > 0)
    {
        t = n % 10;
        num += pow(t, k);
        n /= 10;
    }
    return num;
}

int dfs(int n)
{
    //cout << n << " ";
    if (n <= 1000000 && check[n])
    {
        if(m[n]==0){
            m[n]=n;
        }
        return m[n];
    }
    if(n<=1000000){
        check[n]=true;
    }
    int val = dfs(get_next_n(n));
    int nx,res;
    res = min(n,val);
    if(n<=1000000 && m[n]!=0){
        nx = get_next_n(n);
        while(nx!=n){
            if(nx<=1000000){
                m[nx]=res;
            }
            nx = get_next_n(nx);
        }
    }
    if(n<=1000000){
        m[n]=res;
    }
    return res;
}

int main()
{
    int i, t, num;
    cin >> a >> b >> k;
    long long sum=0;
    for(i=a;i<=b;i++){
        t = dfs(i);
        sum += t;
        //cout << endl << t << endl;
    }
    cout << sum << endl;
    return 0;
}