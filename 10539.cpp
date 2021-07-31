#include <iostream>

using namespace std;

long long v[101];

int main(){
    int n,i;
    cin >> n;
    for(i=1;i<=n;i++)cin >> v[i];
    for(i=1;i<=n;i++){
        cout << v[i]*i-v[i-1]*(i-1) << " ";
    }
    cout << endl;
    return 0;
}