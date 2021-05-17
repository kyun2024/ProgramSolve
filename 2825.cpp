#include <iostream>
#include <bitset>

using namespace std;

long long b[1024];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n,bx,i,j;
    unsigned long long x,res{};
    cin >> n;
    while(n--){
        cin >> x;
        bx = (1<<(x%10))|
        (x>=10)*(1<<(x/10%10))|
        (x>=100)*(1<<(x/100%10))|
        (x>=1000)*(1<<(x/1000%10))|
        (x>=10000)*(1<<(x/10000%10))|
        (x>=100000)*(1<<(x/100000%10))|
        (x>=1000000)*(1<<(x/1000000%10))|
        (x>=10000000)*(1<<(x/10000000%10))|
        (x>=100000000)*(1<<(x/100000000%10))|
        (x>=1000000000)*(1<<(x/1000000000%10))|
        (x>=10000000000LL)*(1<<(x/10000000000LL%10))|
        (x>=100000000000LL)*(1<<(x/100000000000LL%10))|
        (x>=1000000000000LL)*(1<<(x/1000000000000LL%10))|
        (x>=10000000000000LL)*(1<<(x/10000000000000LL%10))|
        (x>=100000000000000LL)*(1<<(x/100000000000000LL%10))|
        (x>=1000000000000000LL)*(1<<(x/1000000000000000LL%10))|
        (x>=10000000000000000LL)*(1<<(x/10000000000000000LL%10))|
        (x>=100000000000000000LL)*(1<<(x/100000000000000000LL%10))|
        (x>=1000000000000000000LL)*(1<<(x/1000000000000000000LL));
        b[bx]++;
    }
    for(i=1;i<1024;i++){
        res += b[i]*(b[i]-1)/2;
        for(j=i+1;j<1024;j++){
            if(i&j)res += b[i]*b[j];
        }
    }
    cout << res << endl;
    return 0;
}