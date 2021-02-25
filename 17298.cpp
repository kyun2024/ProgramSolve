#include <iostream>
#include <stack>

using namespace std;

int v[1000001];
int p[1000001];

int main(){
    cin.tie(0)->sync_with_stdio(false);

    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }

    stack<pair<int,int>> s;
    pair<int,int> t;

    for(i=1;i<=n;i++){
        while(!s.empty()){
            t = s.top();
            if(t.first<v[i]){
                p[t.second]=v[i];
                s.pop();
            }
            else break;
        }
        s.push({v[i],i});
    }
    while(!s.empty()){
        p[s.top().second]=-1;
        s.pop();
    }
    for(i=1;i<=n;i++){
        cout << p[i] << " ";
    }
    cout << endl;
    return 0;
}