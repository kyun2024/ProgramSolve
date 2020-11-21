#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int d[100001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<int,vector<int>,less<int>> left_pq;
    priority_queue<int,vector<int>,greater<int>> right_pq;

    int n;
    int i,t;
    cin >> n;
    for(i=1;i<=n;i++)cin>>d[i];
    left_pq.push(d[1]);
    cout << d[1] << '\n';
    for(i=2;i<=n;i++){
        t = d[i];
        if(i%2==1){
            //push left
            if(right_pq.top()<d[i]){
                t = right_pq.top();
                right_pq.pop();
                right_pq.push(d[i]);
            }
            left_pq.push(t);
        }
        else{
            //push right
            if(left_pq.top()>d[i]){
                t = left_pq.top();
                left_pq.pop();
                left_pq.push(d[i]);
            }
            right_pq.push(t);
        }
        cout << left_pq.top() << '\n';
    }
    return 0;
}