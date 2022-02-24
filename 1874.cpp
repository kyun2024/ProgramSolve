#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

int m[100001];

int main(){
    int next_p = 1;
    int n,i,j;
    stack<int> s;
    ostringstream oss;

    cin >> n;
    for(i=1;i<=n;i++)cin >> m[i];

    for(i=1;i<=n;i++){
        while(next_p<=m[i])
        {
            s.push(next_p);
            next_p++;
            oss << "+\n";
        }
        if(s.top() == m[i]){
            s.pop();
            oss <<"-\n";
        }
        else break;
    }
    if(i>n)cout << oss.str();
    else cout << "NO\n";
    return 0;
}