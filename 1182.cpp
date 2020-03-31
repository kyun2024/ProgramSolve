#include <iostream>

using namespace std;

int n,k;
int res;
int a[21],m[21];
int i;
void q(int c){
    if(c==n){
        int s{};
        for(i=0;i<n;i++){
            s+=a[i]*m[i];
        }
        res += s==k;
        return;
    }
    m[c]=0;
    q(c+1);
    m[c]=1;
    q(c+1);
}
int main(){
    cin >> n >> k;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    q(0);
    cout << res - (k==0) << endl;
    return 0;
}