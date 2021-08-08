#include <iostream>

using namespace std;

int main(){
    int t,tc;
    long long a,b,c;
    cin >> t;
    for(tc=1;tc<=t;tc++){
        cin >> a >> b >> c;
        cout << "Scenario #" << tc << ":\n";
        if(a*a+b*b==c*c || b*b+c*c==a*a || c*c+a*a==b*b){
            cout << "yes\n\n";
        }
        else cout << "no\n\n";
    }
    return 0;
}