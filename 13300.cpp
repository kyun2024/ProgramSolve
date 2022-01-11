#include <iostream>

using namespace std;

int m[2][7];

int main(){
    int n,k;
    int s,y;
    cin >> n >> k;
    while(n--){
        cin >> s >> y;
        m[s][y]++;
    }
    int i,j,res=0;
    for(i=0;i<2;i++){
        for(j=1;j<=6;j++){
            res += (m[i][j]+k-1)/k;
        }
    }
    cout << res << endl;
    return 0;
}