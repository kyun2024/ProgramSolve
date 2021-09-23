#include <iostream>

using namespace std;

int main(){
    int t,i;
    long long n,a,s;

    cin >> t;
    while(t--){
        cin >> n;
        for(s=i=0;i<n;i++){
            cin >> a;
            a%=n;
            s = (s+a)%n;
        }
        cout << (s?"NO":"YES") << endl;
    }
    return 0;
}