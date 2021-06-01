#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<char> s;
    int n,b,r;
    cin >> n >> b;
    while(n>0){
        r = n%b;
        n/=b;
        if(r<10)s.push(r+'0');
        else s.push(r-10+'A');
    }
    while(!s.empty()){cout << s.top();s.pop();}
    cout << endl;
    return 0;
}