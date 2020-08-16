#include <iostream>

using namespace std;

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    int r = a%b;
    return gcd(b,r);
}

int lcm(int a,int b){
    return a*b/gcd(a,b);
}

int main(){
    int a[5];
    int i,j,k;
    int res = 1e9;
    for(i=0;i<5;i++)cin >> a[i];
    for(i=0;i<3;i++){
        for(j=i+1;j<4;j++){
            for(k=j+1;k<5;k++){
                res = min(res,lcm(lcm(a[i],a[j]),a[k]));
            }
        }
    }
    cout << res << endl;
    return 0;
}