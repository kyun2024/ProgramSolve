#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<int> v;
    cin >> n;
    v.resize(n+1,0);
    v[0]=1;
    if(n%2==1){
        cout << 0 << endl;
        return 0;
    }
    int i,j;
    for(i=2;i<=n;i+=2){
        for(j=2;i-j>=0;j++){
            if(j==2){
                v[i]+=v[i-j]*3;
            }
            else{
                v[i]+=v[i-j]*2;
            }
        }
    }
    cout << v[n] << endl;
    return 0;
}