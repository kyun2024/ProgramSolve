#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(b>a)swap(a,b);
    while(b!=0){
        int t = a%b;
        a = b;
        b = t;
    }
    return a;
}

bool div_check[15000001];
int min_div[15000001];
unsigned long long cnt[15000001];

unsigned long long pow_rmd[64];
bool pow_bit[64];

constexpr int mod_n = 1000000007;

unsigned long long fastpow(int base,unsigned long long x){
    int i,len;
    for(i=0;x>0;i++){
        pow_bit[i]=x%2;
        x/=2;
    }
    len = i;
    pow_rmd[0]=base;
    for(i=1;i<len;i++){
        pow_rmd[i]=(pow_rmd[i-1]*pow_rmd[i-1])%mod_n;
    }
    x = 1;
    for(i=0;i<len;i++){
        if(pow_bit[i])x = (x * pow_rmd[i])%mod_n;
    }
    return x;
}

int main(){
    int i,j;
    min_div[1]=1;
    div_check[1]=true;
    for(i=2;i<=15000000;i++){
        if(!div_check[i]){
            div_check[i]=true;
            min_div[i]=i;
            for(j=2*i;j<=15000000;j+=i){
                if(!div_check[j]){
                    div_check[j]=true;
                    min_div[j]=i;
                }
            }
        }
    }
    int n,m;
    cin >> n >> m;
    int d,dr,nr;
    for(i=2;i<=n;i++){
        dr = d = min_div[i];
        nr = i;
        while(true){
            cnt[d]+=m/dr;
            if(d==nr)break;
            nr = nr/d;
            if(min_div[nr]==d){
                dr *= d;
            }
            else{
                dr = min_div[nr];
            }
            d = min_div[nr];
        }
    }
    unsigned long long res=1;
    for(i=1;i<=15000000;i++){
        if(cnt[i]!=0){
            res = (res * fastpow(i,cnt[i]))%mod_n;
            //cout << i << " " << cnt[i] << " " << fastpow(i,cnt[i]) << endl;
        }
    }
    cout << res << endl;
    return 0;
}