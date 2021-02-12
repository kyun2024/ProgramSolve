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

    int n,m;
    int i;
    long long a,b,c;
    cin >> n >> m;
    vector<long long> tree_vec, data_vec;
    tree_vec.resize(4*n);
    data_vec.resize(n+1);
    for(i=1;i<=n;i++){
        data_vec[i] = 0;
    }
    init(data_vec,tree_vec,1,1,n);
    for(i=0;i<m;i++){
        cin >> a >> b >> c;
        if (a==0) // sum
        {
            if(b>c)swap(b,c);
            cout << sum(tree_vec, 1, 1, n, b, c) << '\n';
        }
        else{ // update
            update(tree_vec, 1, 1, n, b, c-data_vec[b]);
            data_vec[b]=c;
        }
    }
    return 0;
}