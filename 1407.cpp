#include <iostream>

using namespace std;

unsigned long long proc(unsigned long long x){
    unsigned long long res=0,i,sub_a,sub_b,k;
    res = x;
    for(i=2;i<=x;i*=2){
        res += (x/i)*(i/2);
    }
    return res;
}
/*
int proc(unsigned long long a,unsigned long long b){
    unsigned long long res=0,i,sub_a,sub_b,k;
    res = (b-a+1);
    for(i=2;i<=62;i++){
        k = 1<<(i-1);
        if(b<k)break;
        sub_a = (a%k==0)*(a/k) + (a%k!=0)*(a/k+1);
        sub_b = b/k;
        //cout << sub_a*(1<<(i-1)) << " " << sub_b*(1<<(i-1)) << " " << (1<<(i-2)) << endl;
        res += (sub_b-sub_a+1)*(1<<(i-2));
    }
    return res;
}
*/

int main(){
    unsigned long long a,b;
    cin >> a >> b;
    cout << proc(b)-proc(a-1) << endl;
    return 0;
}