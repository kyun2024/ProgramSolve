#include <iostream>
#include <iomanip>

using namespace std;

int mt[32][2][2];
int res[2];

int abs_mod(int n){
    if(n<0){
        n = -n;
        n %= 1000;
        n = -n;
    }
    else{
        n%=1000;
    }
    return n;
}

int main(){
    mt[1][0][0]=6;
    mt[1][0][1]=-4;
    mt[1][1][0]=1;
    mt[1][1][1]=0;
    int i;
    for(i=2;i<32;i++){
        mt[i][0][0]=abs_mod(mt[i-1][0][0]*mt[i-1][0][0]+mt[i-1][0][1]*(mt[i-1][1][0]));
        mt[i][0][1]=abs_mod(mt[i-1][0][0]*mt[i-1][0][1]+mt[i-1][0][1]*(mt[i-1][1][1]));
        mt[i][1][0]=abs_mod(mt[i-1][1][0]*mt[i-1][0][0]+mt[i-1][1][1]*(mt[i-1][1][0]));
        mt[i][1][1]=abs_mod(mt[i-1][1][0]*mt[i-1][0][1]+mt[i-1][1][1]*(mt[i-1][1][1]));
    }
    int T,n,t,c1,c2;
    cin >> T;
    for(t=1;t<=T;t++){
        cin >> n;
        n-=1;
        res[0]=6;res[1]=2;
        for(i=1;n>0;i++,n/=2){
            if(n%2){
                c1 = abs_mod(mt[i][0][0]*res[0]+mt[i][0][1]*res[1]);
                c2 = abs_mod(mt[i][1][0]*res[0]+mt[i][1][1]*res[1]);
                res[0] = c1;res[1] = c2;
            }
        }
        cout << "Case #" << t << ": " << setfill('0') << setw(3) << (res[0]+999)%1000 << '\n';
    }
    return 0;
}