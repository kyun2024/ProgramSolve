#include <iostream>

using namespace std;

int m[101];

int main(){
    int n;
    int i,r=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> m[i];
    }
    for(i=n-1;i>=1;i--){
        if(m[i]>=m[i+1]){
            r += m[i]-m[i+1]+1;
            m[i]=m[i+1]-1;
        }
    }
    cout << r << endl;
    return 0;
}
