#include <iostream>
#include <vector>

using namespace std;

int upperbound(vector<int>& dst,int n){
    int s,e,m;
    s=0;
    e=dst.size();
    while(true){
        m=(s+e)>>1;
        if(e<=s)break;
        if(dst[m]<=n){
            s=m+1;
        }
        else{
            e=m;
        }
    }
    return m;
}

int main(){
    vector<int> v,st;
    int n,i,j,res=0,f;
    cin >> n;
    v.resize(n);
    for(auto& x: v){
        cin >> x;
    }
    for(i=0;i<n;i++){
        f = upperbound(st,v[i]);
        if(f==st.size()){
            st.push_back(v[i]);
        }
        else{
            st[f]=v[i];
        }
        if(f>res)res=f;
    }
    cout << res+1 << endl;
    return 0;
}