#include <iostream>

using namespace std;

int v[5001];
int m[5001];

int main(){
    int n;
    int i,j;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    m[0]=m[1]=1;
    for(i=2;i<=n;i++){
        for(j=i-1;j>=0;j--){
            if(v[i]>v[j])m[i]=(m[i]+m[j])%998244353;
        }
    }
    for(i=1;i<=n;i++){
        cout << m[i] << " ";
    }
    cout << endl;
    return 0;
}