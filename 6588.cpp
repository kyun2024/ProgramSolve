#include <iostream>
#include <vector>

int n[1000001];
int p[78498];

using namespace std;

int main(){
    int c=0;
    int i,j;
    for(i=2;i*i<=1'000'000;i++){
        if(n[i]==0){
            for(j=i*i;j<=1'000'000;j+=i){
                n[j]=1;
            }
        }
    }
    for(i=2;i<=1'000'000;i++){
        if(n[i]==0){
            p[c++]=i;
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(true){
        cin >> c;
        if(c==0)break;
        for(i=1;i<100;i++){
            if(n[c-p[i]]==0){
                cout << c << " = " << p[i] << " + " << c-p[i] << " " << '\n';
                break;
            }
        }
    }
}