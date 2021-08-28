#include <iostream>

using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int t,n,max_i,min_i,v;
    cin >> t;
    while(t--){
        cin >> n;
        n--;
        cin >> v;
        max_i = min_i = v;
        while(n--){
            cin >> v;
            max_i = max(max_i,v);
            min_i = min(min_i,v);
        }
        cout << min_i << " " << max_i << '\n';
    }
    return 0;
}