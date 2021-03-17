#include <iostream>

using namespace std;

int a[10][10];

int main(){
    int n,i,j;
    int cx,mx;
    cin >> n;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin >> a[i][j];
        }
    }
    for(i=0;i<n;i++){
        cx=1;
        mx=a[0][i];
        for(j=1;j<n;j++){
            if(mx<a[j][i]){
                mx=a[j][i];
                cx++;
            }
        }
        cout << cx << " ";
    }
    cout << endl;
    for(i=0;i<n;i++){
        cx=1;
        mx=a[i][0];
        for(j=1;j<n;j++){
            if(mx<a[i][j]){
                mx=a[i][j];
                cx++;
            }
        }
        cout << cx << endl;
    }
    return 0;
}