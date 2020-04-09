#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){
    int i,k;
    long long a{},b{},r{};
    stack<int> s;
    string st;

    cin >> st;
    for(i=st.length()-1,k=1;i>=0;i--,k*=2){
        a += (st[i]-'0')*k;
    }
    cin.get();
    cin >> st;
    for(i=st.length()-1,k=1;i>=0;i--,k*=2){
        b += (st[i]-'0')*k;
    }
    r = a * b;
    while(r>0){
        s.push(r%2);
        r>>=1;
    }
    while(!s.empty()){
        cout << s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}