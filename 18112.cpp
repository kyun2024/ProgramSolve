#include <iostream>
#include <string>
#include <queue>

using namespace std;

int m[1024];

int msb(int x){
    x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    return (x & ~(x>>1));
}

int main(){
    string str;
    int s{},t{};
    cin >> str;
    for(auto c : str)s = 2*s+c-'0';
    cin >> str;
    for(auto c : str)t = 2*t+c-'0';
    m[s]=1;

    queue<pair<int,int>> q;
    q.push(make_pair(s,1));
    while(!q.empty()){
        int v = q.front().first;
        int c = q.front().second;
        if(v==t)break;
        if(v>0 && m[v-1]==0){
            m[v-1]=c+1;
            q.push(make_pair(v-1,c+1));
        }
        if(v<1023 && m[v+1]==0){
            m[v+1]=c+1;
            q.push(make_pair(v+1,c+1));
        }
        int msb_v = msb(v);
        //cout << v << " " << msb_v << endl;
        for(int i=1;i<msb_v;i<<=1)
        {
            int tog = v^i;
            if(m[tog]==0){
                m[tog]=c+1;
                q.push(make_pair(tog,c+1));
            }
        }
        q.pop();
    }
    cout << m[t]-1 << endl;
    return 0;
}