#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> q;
    int n, k;
    int i,t;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        q.push(i);
    }
    cout << "<";
    while(!q.empty())
    {
        for(i=1;i<k;i++){
            t = q.front();
            q.pop();
            q.push(t);
        }
        t = q.front();
        q.pop();
        cout << t;
        if(!q.empty())cout << ", ";
    }
    cout << ">\n";
    return 0;
}