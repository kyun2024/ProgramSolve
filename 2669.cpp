#include <iostream>

int A[100][100];

using namespace std;

int main(){
    int a,b,c,d;
    int t=0xF;
    while(t & 1){
        cin >> a >> b >> c >> d;
        for(int i=b-1;i<d-1;i++){
            for(int j=a-1;j<c-1;j++){
                A[i][j]=1;
            }
        }
        t >>= 1;
    }
    int res = 0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            res += A[i][j];
        }
    }
    cout << res << endl;
    return 0;
}