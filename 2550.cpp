#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int m[10001],cf[10001];
int bt[10001],lt[10001],ln[10001];
bool ck[10001];

int main(){
    int n;
    int i,j,a,t,k;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a;
        bt[a]=i;
    }
    for(i=1;i<=n;i++){
        cin >> a;
        lt[i]=a;
    }
    for(i=1;i<=n;i++){
        ln[i]=bt[lt[i]];
    }
    
    for(i=1;i<=n;i++){
        t=0;
        k=i;
        for(j=1;j<i;j++){
            if(ln[j]<ln[i]){
                if(t<m[j]){
                    t=m[j];
                    k=j;
                }
            }
        }
        cf[i]=k;
        m[i]=t+1;
    }
    t = 0;
    k = 0;
    for(i=1;i<=n;i++){
        if(t<m[i]){
            t = m[i];
            k = i;
        }
    }
    cout << t << endl;
    stack<int> st;
    st.push(k);
    while(k!=cf[k]){
        k = cf[k];
        st.push(k);
    }
    while(!st.empty()){
        ck[lt[st.top()]]=true;
        st.pop();
    }
    for(i=1;i<=n;i++){
        if(ck[i])cout << i << " ";
    }
    cout << endl;
    return 0;
}