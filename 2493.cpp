#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    vector<int> v,res;
    int n,t,max_idc=0;
    cin >> n;
    v.resize(n,0);
    res.resize(n,0);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    res[0] = 0;
    s.push(0);
    for(int i=1;i<n;i++){
        while(!s.empty() && v[s.top()]<v[i]){
            int tp = s.top();
            s.pop();
            res[tp] = (!s.empty())?s.top()+1:0;
        }
        s.push(i);
    }
    //마무리
    while(!s.empty()){
        int tp = s.top();
        s.pop();
        res[tp] = (!s.empty())?s.top()+1:0;
    }
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}