#include <iostream>
#include <vector>

using namespace std;

long long init(vector<long long>& data, vector<long long>& seg_vec,int node, int start,int end){
    if(start==end){
        return seg_vec[node]=data[end];
    }
    return seg_vec[node]=init(data,seg_vec,2*node,start,(start+end)/2)+
                         init(data,seg_vec,2*node+1,(start+end)/2+1,end);
}

long long sum(vector<long long>& seg_vec, int node, int start, int end, int left, int right){
    if(end<left || right<start){
        return 0;
    }
    else if(left <= start && end <= right){
        return seg_vec[node];
    }
    else return sum(seg_vec, 2*node, start, (start+end)/2, left, right)+
                sum(seg_vec, 2*node+1, (start+end)/2+1, end, left, right);
}

void update(vector<long long>& seg_vec, int node, int start,int end,int index, long long diff){
    if(index < start || end < index)return;
    seg_vec[node] += diff;
    if(start!=end){
        update(seg_vec,2*node,start,(start+end)/2,index,diff);
        update(seg_vec,2*node+1,(start+end)/2+1,end,index,diff);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,m,k;
    int i;
    long long a,b,c;
    cin >> n >> m >> k;
    vector<long long> tree_vec, data_vec;
    tree_vec.resize(4*n);
    data_vec.resize(n);
    for(i=0;i<n;i++){
        cin >> data_vec[i];
    }
    init(data_vec,tree_vec,1,0,n-1);
    for(i=0;i<m+k;i++){
        cin >> a >> b >> c;
        if (a==1) // update
        {
            update(tree_vec, 1, 0, n-1, b-1, c-data_vec[b-1]);
            data_vec[b-1]=c;
        }
        else{ // sum
            cout << sum(tree_vec, 1, 0, n-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}