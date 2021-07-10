#include <iostream>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    long long s,e,m;
    s = 1; e = n*n;
    while(s<=e){
        m = (s+e)/2;
        long long i{},c{},ids{};
        for(i=1;i<=n;i++){
            ids += min(m/i,n);
            c += ((m/i<=n)&&(m%i==0));
        }
        if(ids-c<k && k<=ids){
            cout << m << endl;
            break;
        }
        if(k>ids){
            s = m+1;
        }
        else{
            e = m-1;
        }
    }
    return 0;
}