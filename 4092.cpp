#include <iostream>
#include <bitset>

using namespace std;

long long combi_calc[65][65];
int lut[65];

void proc1(){
    int i,j;
    combi_calc[0][0]=1;
    for(i=1;i<=64;i++){
        combi_calc[i][0]=1;
        for(j=1;j<=i;j++){
            combi_calc[i][j]=combi_calc[i-1][j-1]+combi_calc[i-1][j];
        }
    }

    for(i=2;i<=64;i++){
        lut[i]=lut[__builtin_popcount(i)]+1;
    }
}

long long f(unsigned long long n,unsigned long long top,long long bit){
    if(bit>0 && n==0){
        //cout << n << " " << top << " " << bit << " : " << 0 << endl;
        return 0;
    }
    if(bit==0 || n==0){
        //cout << n << " " << top << " " << bit << " : " << 1 << endl;
        return 1;
    }
    int lz_n = __builtin_clzll(top);
    unsigned long long t = 1ULL<<(64-lz_n-1);
    //cout << lz_n << " " << t << endl;
    if(t & n){
        //cout << bitset<7>(t-1) << endl;
        long long res = f(t-1,top,bit)+f(n-t,top-t,bit-1);
        //cout << n << " " << top << " " << bit << " : " << res << endl;
        return res;
    }
    else{
        t = __builtin_popcountll(n);
        //cout << n << " " << top << " " << bit << " : " << ((bit<=t)?combi_calc[__builtin_popcountll(n)][bit]:0) << endl;
        return (bit<=t)?combi_calc[__builtin_popcountll(n)][bit]:0;
    }
}

int main(){
    proc1();
    long long lo,hi,k;
    while(true){
        cin >> lo >> hi >> k;
        if(lo==hi && hi==k && k==0)break;
        if(k==0){
            cout << (lo==1) << endl;
            continue;
        }
        long long res{};
        for(int i=1;i<=64;i++){
            if(lut[i]==k-1){
                //cout << "i : " << i << endl;
                res += f(hi,hi,i)-f(lo-1,lo-1,i);
                //cout << endl;
            }
        }
        if(lo == 1 && k==1)res--;
        cout << res << endl;
    }
    return 0;
}