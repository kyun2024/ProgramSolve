#include <iostream>

using namespace std;

int memo[5];
int v[8];

int main(){
    int i,j,k,l,m;
    int res=0;
    for(i=0;i<8;i++)cin >> v[i];
    for(i=0;i<8;i++){
        for(j=i+1;j<8;j++){
            for(k=j+1;k<8;k++){
                for(l=k+1;l<8;l++){
                    for(m=l+1;m<8;m++){
                        if(v[i]+v[j]+v[k]+v[l]+v[m]>res){
                            res = v[i]+v[j]+v[k]+v[l]+v[m];
                            memo[0]=i;
                            memo[1]=j;
                            memo[2]=k;
                            memo[3]=l;
                            memo[4]=m;
                        }
                    }
                }
            }
        }
    }
    cout << res << endl;
    for(i=0;i<5;i++)cout << memo[i]+1 << " ";
    cout << endl;
    return 0;
}
