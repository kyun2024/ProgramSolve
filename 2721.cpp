#include <iostream>

using namespace std;

int m[302];

int main(){
    int i;
    for(i=1;i<=301;i++){
        m[i]=m[i-1]+i;
    }
    int T,n;
    cin >> T;
    int s;
    while(T--)
    {
        cin >> n;
        s = 0;
        for(i=1;i<=n;i++){
            s += m[i+1]*i;
        }
        cout << s << endl;
    }
    return 0;
}