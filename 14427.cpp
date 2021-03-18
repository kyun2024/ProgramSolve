#include <iostream>
#include <vector>

using namespace std;

int init(vector<int>& data,vector<int>& seg_vec,int node,int start,int end){
    if(start==end){
        return seg_vec[node] = end;
    }
    
    int i1,i2;
    i1 = init(data,seg_vec,2*node,start,(start+end)/2);
    i2 = init(data,seg_vec,2*node+1,(start+end)/2+1,end);
    if(data[i1]==data[i2]){
        return seg_vec[node]=min(i1,i2);
    }
    else{
        if(data[i1]<data[i2]){
            return seg_vec[node]=i1;
        }
        else{
            return seg_vec[node]=i2;
        }
    }
}

void update(vector<int>& data,vector<int>& seg_vec, int node,int start,int end,int index){
    if(start==end)return;
    if(index<=(start+end)/2){
        update(data,seg_vec,2*node,start,(start+end)/2,index);
    }
    else{
        update(data,seg_vec,2*node+1,(start+end)/2+1,end,index);
    }
    int i1,i2;
    i1 = seg_vec[2*node];
    i2 = seg_vec[2*node+1];
    if(data[i1]==data[i2]){
        seg_vec[node]=min(i1,i2);
    }
    else{
        if(data[i1]<data[i2]){
            seg_vec[node]=i1;
        }
        else{
            seg_vec[node]=i2;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    int i,a,b,c;
    vector<int> data_vec,tree_vec;
    cin >> n;
    data_vec.resize(n+1);
    tree_vec.resize(4*n);
    for(i=1;i<=n;i++){
        cin >> data_vec[i];
    }
    init(data_vec,tree_vec,1,1,n);
    cin >> m;
    for(i=0;i<m;i++){
        cin >> a;
        if(a==1){
            cin >> b >> c;
            data_vec[b]=c;
            update(data_vec,tree_vec,1,1,n,b);
        }
        else{
            cout << tree_vec[1] << '\n';
        }
    }
    return 0;
}