#include <iostream>

using namespace std;

constexpr unsigned long long max_v = (1ULL<<32)-1;

int main(){
    unsigned long long int n;
    cin >> n;
    if(n==0)cout << 0 << endl;
    else if(n==1)cout << 1 << endl;
    else if(n<=4)cout << 2 << endl;
    else if(n<=9)cout << 3 << endl;
    else{
        unsigned long long int s,e,m;
        s = 1;
        e = min(n>>1,max_v);
        while(s<e){
            m = (s+e)>>1;
            //cout << m << " " << m*m << " " << (m*m<n) << endl;
            if(m*m<n){
                s=m+1;
            }
            else{
                e=m;
            }
        }
        cout << e << endl;
    }
    return 0;
}