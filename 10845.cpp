#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string s;
    queue<int> q;
    int T,x;
    cin >> T;
    cin.get();
    while(T--){
        cin >> s;
        if(s.compare("push")==0){
            cin >> x;
            cin.get();
            q.push(x);
        }
        else if(s.compare("pop")==0){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(s.compare("size")==0){
            cout << q.size() << '\n';
        }
        else if(s.compare("empty")==0){
            cout << q.empty() << '\n';
        }
        else if(s.compare("front")==0){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.front() << '\n';
            }
        }
        else if(s.compare("back")==0){
            if(q.empty()){
                cout << -1 << '\n';
            }
            else{
                cout << q.back() << '\n';
            }
        }
    }
    return 0;
}