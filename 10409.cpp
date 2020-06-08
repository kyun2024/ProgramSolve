#include <iostream>

using namespace std;

int main(){
    int n,t;
    int i,a,s{};
    cin >> n >> t;
    for(i=0;i<n;i++){
        cin >> a;
        if(s+a>t)break;
        s+=a;
    }
    cout << i << endl;
    return 0;
}