#include <iostream>

using namespace std;

int a[100][100],b[100][100];

int main(){
    int r,c;
    int i,j;
    cin >> r >> c;
    for(i=0;i<r;i++)for(j=0;j<c;j++)cin>>a[i][j];
    for(i=0;i<r;i++)for(j=0;j<c;j++)cin>>b[i][j];
    for(i=0;i<r;i++)for(j=0;j<c;j++)a[i][j]+=b[i][j];
    for(i=0;i<r;i++,cout<<"\n")for(j=0;j<c;j++)cout<<a[i][j]<<" ";
    return 0;
}