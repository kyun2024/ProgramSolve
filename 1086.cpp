#include <iostream>
#include <string>

using namespace std;

string v[15];
long long m[(1<<15)][100];
int lut[100][51][100];
int rmd[15];

int bitcount(int n){
    n = ((n&0xAAAA)>>1) + (n&0x5555);
    n = ((n&0xCCCC)>>2) + (n&0x3333);
    n = ((n&0xF0F0)>>4) + (n&0x0F0F);
    n = ((n&0xFF00)>>8) + (n&0x00FF);
    return n;
}

long long gcd(long long a,long long b){
    if(a<b)swap(a,b);
    while(b>0){
        long long t = a%b;
        a = b;
        b = t;
    }
    return a;
}

void set_lookup(int mod_n){
    int i,j,k,l,t;
    for(i=0;i<mod_n;i++){
        for(j=0;j<mod_n;j++){
            for(k=1;k<=50;k++){
                t = i;
                for(l=0;l<k;l++){
                    t = (10*t)%mod_n;
                }
                t = (t + j)%mod_n;
                lut[i][k][j]=t;
            }
        }
    }
}

int main(){
    int n,k;
    cin >> n;
    int i,j,l,it1,it2;
    cin.get();
    for(i=0;i<n;i++){
        getline(cin,v[i]);
    }
    cin >> k;
    set_lookup(k);
    int t;
    for(i=0;i<n;i++){
        t = (v[i][0]-'0')%k;
        for(j=1;j<v[i].length();j++){
            t = (10*t+v[i][j]-'0')%k;
        }
        rmd[i]=t;
        m[1<<i][t]=1;
    }

    for(j=1;j<n;j++){
        for(i=0;i<n;i++){
            for(l=1;l<(1<<n);l++){
                if(bitcount(l)!=j)continue;
                for(it1=0;it1<k;it1++){
                    if(m[l][it1] && (l&(1<<i))==0){
                        m[l|(1<<i)][lut[it1][v[i].length()][rmd[i]]] += m[l][it1];
                    }
                }
            }
        }
    }
    long long num{}, deno{};
    num = m[(1<<n)-1][0];
    for(i=0;i<k;i++){
        deno += m[(1<<n)-1][i];
    }
    long long gcd_v = gcd(num,deno);
    cout << (num/gcd_v) << "/" << (deno/gcd_v) << endl;
    return 0;
}