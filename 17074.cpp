#include <iostream>

using namespace std;

bool l[100002],r[100002],m[100002];
int a[100001];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    l[0]=l[1]=1;
    for(i=2;i<=n;i++){
        if(a[i-1]>a[i]){
            break;
        }
        l[i]=1;
    }

    r[n+1]=r[n]=1;
    for(i=n-1;i>=1;i--){
        if(a[i]>a[i+1]){
            break;
        }
        r[i]=1;
    }
    
    m[1]=m[n]=1;
    for(i=2;i<n;i++){
        if(a[i-1]<=a[i+1]){
            m[i]=1;
        }
    }
    
    int s=0;
    for(i=1;i<=n;i++){
        s += l[i-1]*r[i+1]*m[i];
    }
    cout << s << endl;
    return 0;
}