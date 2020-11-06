#include <iostream>

using namespace std;

int m[1000001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int i,j;
    for(i=1;i<=1000000;i++){
        for(j=1;j*j<=i;j++){
            if(m[i-j*j]==0){
                m[i]=1;
                break;
            }
        }
    }
    int n;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> j;
        if(m[j]){
            cout << "koosaga\n";
        }
        else{
            cout << "cubelover\n";
        }
    }
    return 0;
}