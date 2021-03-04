#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

//bitset<2000001> b;
bool b[2000001];

int main(){
    int n,c,cnt=0;
    int i,j,x;
    cin >> n >> c;
    for(i=1;i<=n;i++){
        cin >> x;
        for(j=x;j<=c;j+=x){
            b[j]=true;
        }
    }
    for(i=1;i<=c;i++){
        cnt+=b[i];
    }
    cout << cnt << endl;
    return 0;
}