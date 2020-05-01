#include <iostream>

using namespace std;

int a[101],r[101];

int main(){
    int n,i,j,t;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
        r[i]=i;
    }
    for(i=1;i<=n;i++){
        t=r[i];
        for(j=i-1;j>=i-a[i];j--){
            r[j+1]=r[j];
        }
        r[i-a[i]]=t;
    }
    for(i=1;i<=n;i++){
        cout << r[i] << " "; 
    }
    cout << endl;
    return 0;
}