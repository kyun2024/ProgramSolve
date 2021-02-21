#include <iostream>
#include <vector>

using namespace std;

int seg_a[400000];
int dt_a[100001];

int init(int n, int s,int e){
    if(s==e){
        return seg_a[n]=dt_a[e];
    }
    return seg_a[n] = min(init(2*n,s,(s+e)/2),init(2*n+1,(s+e)/2+1,e));
}

void update(int n,int s,int e,int idx, int d){
    if(idx<s || e<idx){
        return;
    }
    seg_a[n]+=d;
    if(s!=e){
        update(2*n,s,(s+e)/2,idx,d);
        update(2*n+1,(s+e)/2+1,e,idx,d);
    }
}

int seg_min(int n,int s,int e,int rb,int re){
    int res;
    if(re<s || e<rb){
        res = 1000000001;
    }
    else if(s==e || (rb <= s && e <= re)){
        res = seg_a[n];
    }
    else res = min(seg_min(2*n,s,(s+e)/2,rb,re),seg_min(2*n+1,(s+e)/2+1,e,rb,re));
    //cout << s << " " << e << " " << rb << " " << re << " " << res << endl;
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,q;
    int i;
    int a,b;
    cin >> n >> q;
    for(i=0;i<n;i++){
        cin >> dt_a[i];
    }
    init(1,0,n-1);
    for(i=0;i<q;i++){
        cin >> a >> b;
        cout << seg_min(1,0,n-1,a-1,b-1) << '\n';
    }

    return 0;
}