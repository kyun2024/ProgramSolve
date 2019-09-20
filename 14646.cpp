#include <iostream>
#include <vector>

using namespace std;

int main(){
    //input setting
    //std::ios::sync_with_stdio(false);
    //cin.tie(0);


    int N{},res{},cnt{};
    int i{};
    vector<int> V,A;
    cin >> N;
    V.resize(2*N,0);
    A.resize(N+1,0);

    for(auto &x : V){
        cin >> x;
    }
    for(i=0;i<V.size();i++){
        if(A[V[i]]==0){
            cnt+=1;
            if(res<cnt){
                res=cnt;
            }
        }
        else if(A[V[i]]==1){
            cnt-=1;
        }
        A[V[i]]+=1;
    }
    cout << res << endl;
    return 0;
}