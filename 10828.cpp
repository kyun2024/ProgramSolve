#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int lines,n;
    string input;
    stack<int> s;
    cin >> lines;
    cin.get();
    while(--lines >= 0){
        cin >> input;
        if(input == "push"){
            cin >> n;
            cin.get();
            s.push(n);
        }
        if(input == "top"){
            if(s.empty()){
                cout << -1 << endl;
            }
            else cout << s.top() << endl;
        }
        if(input == "pop"){
            if(s.empty()){
                cout << -1 << endl;
            }
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        if(input == "size"){
            cout << s.size() << endl;
        }
        if(input == "empty"){
            cout << s.empty() << endl;
        }
    }
    return 0;
}