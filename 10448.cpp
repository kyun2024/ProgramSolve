#include <iostream>

using namespace std;

bool check[1001];

int main(){
    int i,j,k;
    for(i=1;i*(i+1)/2<=1000;i++){
        for(j=i;j*(j+1)/2<=1000;j++){
            if(i*(i+1)/2+j*(j+1)/2>=1000)break;
            for(k=j;k*(k+1)/2<=1000;k++){
                if(i*(i+1)/2+j*(j+1)/2+k*(k+1)/2>1000)break;
                check[i*(i+1)/2+j*(j+1)/2+k*(k+1)/2]=true;
            }
        }
    }
    cin >> k;
    while(k--){
        cin >> i;
        cout << check[i] << endl;
    }
    return 0;
}