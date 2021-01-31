#include <iostream>

using namespace std;

int v[100001];

int main(){
    int n;
    int i,c,m;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    c = 1;
    m = v[n];
    for(i=n-1;i>=1;i--){
        if(m<v[i]){
            c++;
            m=v[i];
        }
    }
    cout << c << endl;
    return 0;
}