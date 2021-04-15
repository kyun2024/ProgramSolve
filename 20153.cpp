#include <iostream>

using namespace std;

int b_c[22];
int v[2222222];

int main(){
    int n;
    int k,i,bx,x;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    for(k=0;k<n;k++){
        x = v[k];
        for(i=0;x>0;i++){
            if(x%2){
                b_c[i]++;
            }
            x/=2;
        }
    }
    int s=0,res=0;
    for(i=0,bx=1;i<22;i++,bx*=2){
        if(b_c[i]%2)s+=bx;
    }
    res = s;
    for(k=0;k<n;k++){
        x = v[k];
        for(i=0;x>0;i++){
            if(x%2){
                b_c[i]--;
            }
            x/=2;
        }
        s=0;
        for(i=0,bx=1;i<22;i++,bx*=2){
            if(b_c[i]%2)s+=bx;
        }
        res = max(res,s);
        x = v[k];
        for(i=0;x>0;i++){
            if(x%2){
                b_c[i]++;
            }
            x/=2;
        }
    }
    cout << res << res << endl;
    return 0;
}
