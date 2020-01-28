#include <iostream>

using namespace std;

int q(int a){
    if(a<0)return 0;
    if(a==0)return 1;
    return q(a-3)+q(a-2)+q(a-1);
}

int main(){
    int n,t;
    cin >> n;
    while(--n>=0){
        cin >> t;
        cout << q(t) << endl;
    }
    return 0;
}