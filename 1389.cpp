#include <iostream>
#include <vector>

using namespace std;

int main(){
    int node, edge;
    vector<vector<int>> v;

    int i,j,k;

    cin >> node >> edge;
    v.resize(node,vector<int>(node,10000));

    for(i=0;i<edge;i++){
        cin >> j >> k;
        v[j-1][k-1]=v[k-1][j-1]=1;
    }

    for(i=0;i<node;i++){
        for(j=0;j<node;j++){
            for(k=0;k<node;k++){
                if(v[j][k] > v[j][i] + v[i][k]){
                    v[j][k] = v[j][i] + v[i][k];
                }
            }
        }
    }
    int sum,res=1e9;
    k=0;
    for(i=0;i<node;i++){
        sum=0;
        for(j=0;j<node;j++)sum+=(j!=i)?v[i][j]:0;
        if(sum<res){
            res=sum;
            k=i;
        }
    }
    cout << k+1 << endl;
    return 0;
}