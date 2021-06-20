#include <iostream>

using namespace std;

bool is_prime(unsigned long long n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

unsigned long long d(unsigned long long n){
    //cout << "d : " << n << endl;
    if(is_prime(n))return 2;
    unsigned long long i,c=2;
    for(i=2;i<=n/2;i++){
        c += !(n%i);
    }
    return c;
}

int main(){
    unsigned long long n,nd;
    cin >> n;
    //cout << is_prime(n) << endl;
    //cout << d(n) << endl;
    //return 0;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    unsigned long long s,e,m;
    for(int i=30;i>=2;i--){
        s = 2;e = n;
        while(s<=e){
            m = (s+e)>>1;
            nd = n;
            for(int j=0;j<i;j++){
                nd /= m;
            }
            //cout << n << " / " << m << "^" << i << " = " << nd << " : " << (n%m) << endl;
            if(nd==1 && n%m==0){
                unsigned long long t=1;
                for(int j=0;j<i;j++){
                    t *= m;
                }
                if(t == n){
                    if(i==2){
                        if(is_prime(m)){
                            cout << m << endl;
                            return 0;        
                        }
                    }
                    else if(d(m)==i){
                        cout << m << endl;
                        return 0;
                    }
                }
            }
            if(nd==0){
                e = m-1;
            }
            else{
                s = m+1;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}