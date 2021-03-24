#include <iostream>

using namespace std;

int seg_a[400000];
int dt_a[100000];

int init(int n,int s,int e){
    if(s==e){
        return seg_a[n]=dt_a[e];
    }
    int res = min(init(2*n,s,(s+e)/2),init(2*n+1,(s+e)/2+1,e));
    return seg_a[n]=res;
}

int get_node(int n,int s,int e,int idx){
    if(s==e)return n;
    if(idx<=(s+e)/2){
        return get_node(2*n,s,(s+e)/2,idx);
    }
    else{
        return get_node(2*n+1,(s+e)/2+1,e,idx);
    }
}

void update(int n,int cv){
    seg_a[n]=cv;
    n/=2;
    while(n>0){
        seg_a[n]=min(seg_a[2*n],seg_a[2*n+1]);
        n/=2;
    }
}

int seg_min(int n,int s,int e,int rb,int re){
    if(re<s || e<rb)return 1000000001;
    if(rb<=s && e<=re)return seg_a[n];
    return min(seg_min(2*n,s,(s+e)/2,rb,re),seg_min(2*n+1,(s+e)/2+1,e,rb,re));
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    int i;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> dt_a[i];
    }
    init(1,0,n-1);
    int q;
    int a,b,c;
    cin >> q;
    for(i=0;i<q;i++){
        cin >> a >> b >> c;
        if(a==1){
            //change
            update(get_node(1,0,n-1,b-1),c);
        }
        else{
            //min
            cout << seg_min(1,0,n-1,b-1,c-1) << '\n';
        }
    }
    return 0;
}