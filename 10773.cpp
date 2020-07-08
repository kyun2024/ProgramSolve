#include <iostream>
#include <stack>

using namespace std;

int main(){
    stack<int> s;
    int n,a,sum_val{};
    cin >> n;
    while(n--){
        cin >> a;
        if(a==0){
            s.pop();
        }
        else s.push(a);
    }
    while(!s.empty()){
        sum_val += s.top();
        s.pop();
    }
    cout << sum_val << endl;
    return 0;
}