#include <iostream>

using namespace std;

int m[1001];

int main(){
    int i,j,idx=0;
    for(i=1;i<=1000;i++){
        for(j=0;j<i;j++){
            if(idx<1000){
                m[++idx]=i;
            }
            else break;
        }
    }
    cin >> i >> j;
    idx = 0;
    while(i<=j){
        idx += m[i];
        i++;
    }
    cout << idx << endl;
    return 0;
}