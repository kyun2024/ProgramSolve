#include <iostream>
#include <deque>

using namespace std;

int ball_color[200001];
int ball_size[200001];
deque<long long> size_deq[2001];
long long color_sum[200001];
long long total_sum=0;
long long res[200001];

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    
    long long total_sum=0;

    int n,i,j;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> ball_color[i] >> ball_size[i];
        size_deq[ball_size[i]].push_back(i);
    }
    for(int i : size_deq[1]){
        color_sum[ball_color[i]] += 1;
        total_sum += 1;
    }
    for(i=2;i<=2000;i++){
        for(int j : size_deq[i]){
            res[j] = total_sum - color_sum[ball_color[j]];
        }
        for(int j : size_deq[i]){
            color_sum[ball_color[j]] += i;
            total_sum += i;
        }        
    }
    for(i=1;i<=n;i++){
        cout << res[i] << '\n';
    }
    return 0;
}