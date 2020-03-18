#include <iostream>

using namespace std;

int A[31];

int main(){
    int i;
    int d,m;
    cin >> d >> m;
    A[1]=1;
    A[2]=1;
    for(i=3;i<=30;i++){
        A[i]=A[i-1]+A[i-2];
    }
    for(i=1;A[d-2]*i<100000;i++){
        if((m-A[d-2]*i)%A[d-1]==0){
            cout << i << endl << (m-A[d-2]*i)/A[d-1] << endl;
            break;
        }
    }
    return 0;
}