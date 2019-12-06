#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main(){
    int n,g;
    int i;
    vector<int> il,a1,a2;
    cin >> n >> g;
    il.resize(g+1,0);
    a1.resize(g+1,0);
    a2.resize(g+1,0);
    for(i=0;i<n;i++){
        cin >> il[i];
    }
    //Iter Lambda
    auto calc_coin = [g](vector<int>& cur,vector<int>& bef,int coin){
        int i,j;
        for(i=0;i<min(coin,g+1);i++){
            cur[i] = bef[i];
        }
        for(;i<=g;i++){
            cur[i] = 0;
            for(j=i;j>=0;j-=coin){
                cur[i] += bef[j];
            }
        }
    };

    // at first, vector a1 is 'before' vector
    // vector a2 is 'current' vector
    // fill 1 at index 0
    a1[0] = 1;

    for(i=0;i<n;i++){
        if(i%2==0){
            calc_coin(a2,a1,il[i]);
        }
        else{
            calc_coin(a1,a2,il[i]);
        }
    }
    if(n%2 == 0){
        cout << a1[g] << endl;
    }
    else cout << a2[g] << endl;
    return 0;
}