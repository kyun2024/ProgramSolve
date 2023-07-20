#include <iostream>
#include <bitset>

using namespace std;


int q[200001][2];
bitset<200001> check;

int main()
{
    int N, K;
    cin >> N >> K;
    int b{}, e=1, i;
    q[0][0] = N;
    check[q[0][0]] = 1;
    while(b<e)
    {
        if(q[b][0] == K)break;
        for(i=2;q[b][0] != 0 && q[b][0]*i<=200000;i*=2)
        {
            if(!check[q[b][0]*i])
            {
                check[q[b][0]*i]=1;
                q[e][0]=i*q[b][0];
                q[e][1]=q[b][1];
                ++e;
            }    
        }
        if(q[b][0]>0 && !check[q[b][0]-1])
        {
            check[q[b][0]-1]=1;
            q[e][0]=q[b][0]-1;
            q[e][1]=q[b][1]+1;
            ++e;
        }
        if(q[b][0]<200000 && !check[q[b][0]+1])
        {
            check[q[b][0]+1]=1;
            q[e][0]=q[b][0]+1;
            q[e][1]=q[b][1]+1;
            ++e;
        }
        ++b;
    }
    cout << q[b][1] << endl;
    return 0;
}