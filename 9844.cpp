#include <iostream>
#include <algorithm>

using namespace std;

int m[502][502],a[501][501];

int main(){
    int r,c;
    int i,j;
    cin >> r >> c;
    for(i=1;i<=r;i++)for(j=1;j<=c;j++){
        cin >> a[i][j];
    }
    for(i=1;i<=r;i++)for(j=1;j<=c;j++){
        m[i][j]=max(m[i-1][j-1],max(m[i-1][j],m[i-1][j+1]))+a[i][j];
    }
    cout << *max_element(m[r]+1,m[r]+c+1) << endl;
    return 0;
}