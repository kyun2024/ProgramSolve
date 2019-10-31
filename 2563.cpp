#include <iostream>
#include <array>

using namespace std;

int main(){
    int i,j,k;
    array<array<int,100>,100> A;
    for(i=0;i<100;i++)A[i].fill(0);
    int N;
    int a,b;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> a >> b;
        for(j=b;j<b+10;j++){
            for(k=a;k<a+10;k++){
                A[j][k]=1;
            }
        }
    }
    int count = 0;
    for(i=0;i<100;i++){
        for(j=0;j<100;j++){
            count += A[i][j];
        }
    }
    cout << count << endl;
    return 0;
}