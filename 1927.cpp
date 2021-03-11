#include <iostream>
#include <queue>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);

    priority_queue<int,vector<int>,greater<int>> pq;
    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        if(x==0){
            if(pq.empty()){
                cout << 0 << '\n';
            }
            else{
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else pq.push(x);
    }
    return 0;
}