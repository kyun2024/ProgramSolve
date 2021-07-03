#include <iostream>

using namespace std;

int m[200001];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> m[i];
    }
    for(i=1;i<=n-3;i++){
        if(m[1]>m[n])m[1]--;
        else m[n]--;
    }
    m[1]--;
    m[n]--;
    cout << max(m[1],m[n]) << endl;
    return 0;
}