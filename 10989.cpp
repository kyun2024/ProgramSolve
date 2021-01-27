#include <iostream>

using namespace std;

int ca[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x;
    cin >> n;
    while(n--){
        cin >> x;
        ca[x]++;
    }
    for(n=1;n<=10000;n++){
        while(ca[n]--){
            cout << n << '\n';
        }
    }
    return 0;
}