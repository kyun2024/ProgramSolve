#include <iostream>
#include <string>

using namespace std;

int m[12][12];

int main(){
    string str;
    int r,c;
    int i,j;
    cin >> r >> c;
    cin.get();
    for(i=1;i<=r;i++){
        getline(cin,str);
        for(j=0;j<c;j++){
            m[i][j+1]=(str[j]=='.');
        }
    }
    for(i=1;i<=r;i++){
        for(j=1;j<=c;j++){
            if(m[i][j]==1 && m[i][j-1]+m[i][j+1]+m[i+1][j]+m[i-1][j]<2){
                cout << 1 << endl;
                return 0;
            }
        }
    }
    cout << 0 << endl;
    return 0;
}