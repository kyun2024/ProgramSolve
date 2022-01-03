#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct cns{
    int c,n,s;
};

int cc[101];

int main(){
    vector<cns> v;
    int n,a,b,c,i;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        v.push_back({a,b,c});    
    }
    sort(v.begin(),v.end(),[](const cns& i,const cns& j){
        if(i.s == j.s){
            if(i.c == j.c){
                return i.n < j.n;
            }
            return i.c < j.c;
        }
        return i.s > j.s;
    });
    n = 3;
    for(i=0;i<v.size() && n;i++){
        if(cc[v[i].c]<2){
            cout << v[i].c << " " << v[i].n << endl;
            cc[v[i].c]++;
            n--;
        }
    }
    return 0;
}