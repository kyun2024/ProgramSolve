#include <iostream>
#include <stack>

using namespace std;

stack<int> s;

int main(){
    long long n;
    cin >> n;
    while(n){
        s.push((n&1));
        n>>=1;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}