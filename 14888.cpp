#include <iostream>

using namespace std;

int nums[11];
int ops[4];
int N;

template <decltype(min<int>) f>
int rec(int v, int i)
{
    int res;
    bool check=false;
    if(i == N-1)
    {
        return v;
    }
    for(int j=0;j<4;++j)
    {
        if(ops[j])
        {
            ops[j]--;
            int temp;
            switch(j)
            {
            case 0:
                temp = v+nums[i+1];
                break;
            case 1:
                temp = v-nums[i+1];
                break;
            case 2:
                temp = v*nums[i+1];
                break;
            case 3:
                temp = v/nums[i+1];
                break;
            }
            if(!check)
            {
                check = 1;
                res = rec<f>(temp, i+1);
            } 
            else
            {
                res = f(res, rec<f>(temp, i+1));
            }
            ops[j]++;    
        }
    }
    return res;
}

int main()
{
    int i;
    cin >> N;
    for(i=0;i<N;++i)
    {
        cin >> nums[i];
    }
    for(i=0;i<4;++i)cin >> ops[i];
    cout << rec<max<int>>(nums[0], 0) << endl << rec<min<int>>(nums[0], 0) << endl;
}