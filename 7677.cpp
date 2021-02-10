#include <iostream>
#include <bitset>

using namespace std;

int fibo[10000000];

int get_fibo(int n){
    if(n<=10000000){
        return fibo[n];
    }
    int i1,i2,res;
    if(n%2!=0){
        i1 = get_fibo(n/2);
        i2 = get_fibo(n/2+1);
        res = (i1*i1+i2*i2)%10000;
        if(res<0)res+=10000;
        return res;
    }
    else{
        i1 = get_fibo(n/2+1);
        i2 = get_fibo(n/2-1);
        res = (i1*i1-i2*i2)%10000;
        if(res<0)res+=10000;
        return res;
    }
}

int main(){
    int i,n;
    fibo[1]=fibo[2]=1;
    for(i=3;i<=10000000;i++){
        fibo[i]=(fibo[i-1]+fibo[i-2])%10000;
    }
    while(true){
        cin >> n;
        if(n==-1)break;
        cout << get_fibo(n) << endl;
    }
    return 0;
}