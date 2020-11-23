#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,x,s,r;
    while(true){
        cin >> n;
        if(n==0)break;
        n--;
        cin >> x;
        s = r = x;
        while(n--){
            cin >> x;
            if(s>0){
                s += x;
            }
            else{
                s = x;
            }
            r = max(r,s);
        }
        cout << r << '\n';
    }
    return 0;
}