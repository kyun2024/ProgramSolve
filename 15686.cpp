#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int>> chk;
vector<pair<int,int>> homes;

int get_dist(pair<int,int> a,pair<int,int> b)
{
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int main(){
    int i, j, k, dist=0;
    int r,m,t;
    cin >> r >> m;
    for(i=1;i<=r;i++){
        for(j=1;j<=r;j++){
            cin >> t;
            if(t == 1)
            {
                homes.push_back(make_pair(i,j));
            }
            else if(t == 2){
                chk.push_back(make_pair(i,j));
            }
        }
    }
    int min_sum=987654321, min_dist, sum_x;
    for(i=1;i<=(1<<chk.size())-1;i++){
        if(__builtin_popcount(i)==m)
        {
            sum_x = 0;
            for(k=0;k<homes.size();k++){
                min_dist = 987654321;
                for(j=0,t=i;t;j++,t>>=1)
                {
                    if(t&1)
                    {
                        min_dist = min(min_dist, get_dist(chk[j],homes[k]));
                    }
                }
                sum_x += min_dist;
            }
            min_sum = min(min_sum, sum_x);
        }
    }
    cout << min_sum << endl;
    return 0;
}
