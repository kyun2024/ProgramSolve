#include <iostream>
#include <string>

using namespace std;

int a[51][51];

int main(){
    int i,j,r,c,n,m,res{64},c1;
    string str;
    cin >> n >> m;
    cin.get();
    for(i=1;i<=n;i++){
        getline(cin,str);
        for(j=0;j<m;j++){
            a[i][j+1]=(str[j]=='B');
        }
    }
    for(i=1;i<=n-7;i++){
        for(j=1;j<=m-7;j++){
            c1=0;
            for(r=0;r<8;r++){
                for(c=0;c<8;c++){
                    c1 += (a[i+r][j+c]!=(r*8+c+r%2)%2);
                }        
            }
            res = min(res,min(c1,64-c1));
        }
    }
    cout << res << endl;
    return 0;
}