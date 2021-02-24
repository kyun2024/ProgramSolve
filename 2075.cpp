#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int,vector<int>,greater<int>> pq;
    int n;
    int i,j,a;
    cin >> n;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> a;
            if(pq.size()<n){
                pq.push(a);
            }else{
                if(pq.top()<a){
                    pq.pop();
                    pq.push(a);
                }
            }
        }
    }
    cout << pq.top() << endl;
    return 0;
}