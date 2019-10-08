#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N{};
    int i{},j{},max_val{},res{1};
    vector<int> V,A;
    cin >> N;
    V.resize(N,0);
    A.resize(N,0);
    for(i=0;i<N;i++){
        cin >> V[i];
    }
    A[0]=1;
    for(i=1;i<N;i++){
        max_val = 0;
        for(j=0;j<i;j++){
            if(max_val<A[j] && V[j]<V[i]){
                max_val = A[j];
            }
        }
        A[i] = max_val + 1;
        if(res<A[i]){
            res=A[i];
        }
    }
    cout << res << endl;
    return 0;
}