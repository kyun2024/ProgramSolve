#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;

pair<int,int> sq[21];

int max_height[21];


bool operator<=(pair<int,int> a,pair<int,int> b){
    return a.first<=b.first && a.second <= b.second;
}
ostream& operator<<(ostream& os,pair<int,int> x){
    return os << x.first << " " << x.second;
}

int main(){
    int N;
    cin >> N;
    int i,j;
    for(i=1;i<=N;i++){
        cin >> sq[i].first >> sq[i].second;
    }
    fill_n(max_height,21,1);
     sort(sq+1,sq+N+1,[](auto a,auto b){
        if(a.first == b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    });
    //for(i=1;i<=N;i++)cout << sq[i] << endl;
    for(i=1;i<=N;i++){
        for(j=1;j<=N;j++){
            if(i==j)continue;
            if(sq[j]<=sq[i]){
                max_height[j] = max(max_height[j],max_height[i]+1);
            }
        }
    }
    cout << *max_element(max_height+1,max_height+N+1) << endl;
    return 0;
}