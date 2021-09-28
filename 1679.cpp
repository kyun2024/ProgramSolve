#include <iostream>

using namespace std;

bool memo[50001][51];
int v[1001];

int main(){
    int n,lim;
    int i,j,k;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    cin >> lim;
    for(i=1;i<=50000;i++){
        bool fail = true;
        for(j=1;j<=n;j++){
            if(i-v[j]<0)break;
            if(i-v[j]==0){
                fail = false;
                memo[i][1]=true;
            }
            for(k=1;k<lim;k++){
                if(memo[i-v[j]][k]){
                    fail = false;
                    memo[i][k+1]=true;
                }
            }
        }
        if(fail){
            if(i%2==0){
                cout << "holsoon win at " << i << endl;
            }
            else
            {
                cout << "jjaksoon win at " << i << endl;
            }
            return 0;
        }
    }
    cout << "jjaksoon win at " << i << endl;
    return 0;
}