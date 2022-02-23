#include <iostream>

using namespace std;

constexpr int OB = 1<<15;

int m[1<<15];

int main(){
    int i,j,k,l;
    for(i=1;i*i<OB;i++){
        m[i*i]++;
    }
    for(i=1;i*i<OB;i++){
        for(j=i;i*i+j*j<OB;j++){
            m[i*i+j*j]++;
        }
    }
    for(i=1;i*i<OB;i++){
        for(j=i;i*i+j*j<OB;j++){
            for(k=j;i*i+j*j+k*k<OB;k++){
                m[i*i+j*j+k*k]++;
            }
        }
    }
    for(i=1;i*i<OB;i++){
        for(j=i;i*i+j*j<OB;j++){
            for(k=j;i*i+j*j+k*k<OB;k++){
                for(l=k;i*i+j*j+k*k+l*l<OB;l++){
                    m[i*i+j*j+k*k+l*l]++;
                }
            }
        }
    }
    while(1){
        cin >> i;
        if(i==0)break;
        cout << m[i] << '\n';
    }
    return 0;
}