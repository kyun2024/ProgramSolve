#include <iostream>
#include <iomanip>

using namespace std;

int n;
int m[20][20];
int row_c[20][20];
int col_c[20][20];

bool flag=0;
bool isnotprime[1001];

int v[501];

void bf(int r, int c)
{
    if(r > n){
        flag = 1;
        return;
    }
    for(int i=1;i<=n;++i)
    {
        if(!row_c[r][i] && !col_c[c][i] && 
        ((r==1&&c==1)||
        (r==1&&c!=1&&isnotprime[m[r][c-1]+i])||
        (r!=1&&c==1&&isnotprime[m[r-1][c]+i])||
        (r!=1&&c!=1&& isnotprime[m[r-1][c]+i] && isnotprime[m[r][c-1]+i])))
        {
            m[r][c] = i;
            row_c[r][i] = col_c[c][i] = 1;
            if(c==n)bf(r+1,1);
            else bf(r, c+1);
            if(flag)return;
            row_c[r][i] = col_c[c][i] = 0;
            m[r][c] = 0;
        }
    }
}

int main()
{
    cin.tie(0)->sync_with_stdio(false);

    int i,j;
    isnotprime[1] = 1;
    for(i=2;i<=1000;++i)
    {
        if(!isnotprime[i])
        {
            for(j=2*i;j<=1000;j+=i)
            {
                isnotprime[j]=1;
            }
        }
    }
    cin >> n;
    int odd0, odd1, even0, even1;
    for(odd0=1;odd0<=n;odd0 += 2)
    {
        for(even0=2;even0<=n;even0 += 2)
        {
            if(isnotprime[odd0+even0])
            {
                for(odd1 = 1; odd1 <= n; odd1 += 2)
                {
                    for(even1 = 2; even1 <= n; even1 += 2)
                    {
                        if(odd0 != odd1 && even0 != even1 && isnotprime[odd1 + even1])
                        {
                            goto PASS;
                        }
                    }
                }
            }
        }
    }
PASS:
    v[1] = odd0; v[(n+1)/2] = odd1; v[(n+1)/2+1] = even1; v[n] = even0;
    int odd=1, even=2; 
    for(i=2;i<(n+1)/2;++i)
    {
        while(odd == odd0 || odd == odd1)odd+=2;
        v[i]=odd;
        odd+=2;
    }
    for(i=(n+1)/2+2;i<n;++i)
    {
        while(even == even0 || even == even1)even+=2;
        v[i]=even;
        even+=2;
    }
    for(i=0;i<n;++i){
        for(j=0;j<n;++j)
        {
            cout << v[(i+j)%n+1] << " ";
        }
        cout << '\n';
    }
    
    return 0;
}