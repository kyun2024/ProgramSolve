#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

list<int> child[200001];
int m[2][200001];
bool ck[2][200001];
vector<int> l1,l2;

int va[200001],ca[200001];

int f(int x,bool att){
    int s=0;
    if(ck[att][x]){
        return m[att][x];
    }
    for(list<int>::iterator it=child[x].begin();it!=child[x].end();it++){
        if(att){
            s += f(*it,false);
        }
        else{
            s += max(f(*it,true),f(*it,false));
        }
    }
    if(att){
        s += va[x];
    }
    ck[att][x]=true;
    return m[att][x]=s;
}
void track_natt(vector<int>&,int);
void track_att(vector<int> &v, int x){
    v.push_back(x);
    for(list<int>::iterator it=child[x].begin();it!=child[x].end();it++){
        track_natt(v,*it);
    }
}
void track_natt(vector<int> &v, int x){
    for(list<int>::iterator it=child[x].begin();it!=child[x].end();it++){
        if(m[0][*it]>m[1][*it]){
            track_natt(v,*it);
        }
        else{
            track_att(v,*it);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,i;
    cin >> n;
    l1.reserve(n);
    l2.reserve(n);
    for(i=1;i<=n;i++){
        cin >> va[i];
    }
    for(i=2;i<=n;i++){
        cin >> ca[i];
        child[ca[i]].push_back(i);
    }
    cout << f(1,true) << " " << f(1,false) << endl;
    track_att(l1,1);
    track_natt(l2,1);
    sort(l1.begin(),l1.end());
    sort(l2.begin(),l2.end());
    for(const auto& x : l1){
        cout << x << " ";
    }
    cout << -1 << endl;
    for(const auto& x : l2){
        cout << x << " ";
    }
    cout << -1 << endl;
    return 0;
}