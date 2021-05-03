#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int snail[50][5];

int main(){
    int r1,c1,r2,c2;
    cin >> r1 >> c1 >> r2 >> c2;
    int y,x,cnt;
    int k,i;
    if(r1<=0 && c1<=0 && 0<=r2 && 0<=c2){
        snail[-r1][-c1]=1;
    }
    y=x=0;
    cnt=1;
    for(k=2;k<=10000;k+=2){
        y+=1;x+=1;
        for(i=0;i<k;i++){
            y--;cnt++;
            if(r1<=y && y<=r2 && c1<=x && x<=c2){
                snail[y-r1][x-c1]=cnt;
            }
        }
        for(i=0;i<k;i++){
            x--;cnt++;
            if(r1<=y && y<=r2 && c1<=x && x<=c2){
                snail[y-r1][x-c1]=cnt;
            }
        }
        for(i=0;i<k;i++){
            y++;cnt++;
            if(r1<=y && y<=r2 && c1<=x && x<=c2){
                snail[y-r1][x-c1]=cnt;
            }
        }
        for(i=0;i<k;i++){
            x++;cnt++;
            if(r1<=y && y<=r2 && c1<=x && x<=c2){
                snail[y-r1][x-c1]=cnt;
            }
        }
    }
    int res=0;
    for(i=0;i<=r2-r1;i++){
        for(k=0;k<=c2-c1;k++){
            res = max(res,snail[i][k]);
        }
    }
    int len = to_string(res).length();
    for(i=0;i<=r2-r1;i++){
        for(k=0;k<c2-c1;k++){
            cout << setw(len) << snail[i][k] << " ";
        }
        cout << setw(len) << snail[i][c2-c1] << endl;
    }
    return 0;
}