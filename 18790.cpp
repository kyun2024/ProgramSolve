#include <iostream>

using namespace std;

int n;
bool check[500][500];
int n_count[500];
int cter[1000];
int pr[500];
int first_route[500][500];

bool subprogram(){
    int i,j,k,pos;
    cin >> n;
    for(i=0;i<2*n-1;i++){
        cin >> cter[i];
    }
    if(n==1){
        pr[0]=cter[0];
        return true;
    }
    for(i=0;i<2*n-1;i++){
        for(j=n-1;j>0;j--){
            for(k=0;k<n;k++){
                if(check[j][k]==0 && check[j-1][(k-cter[i]+n)%n]==1)
                {
                    check[j][k]=true;
                    first_route[j][k]=(k-cter[i]+n)%n;
                }
                if(j==n-1 && k==0 && check[j][k]){
                    pos = 0;
                    for(i=n-1;i>0;i--){
                        pr[i]=(pos-first_route[i][pos]+n)%n;
                        pos = first_route[i][pos];
                    }
                    pr[i]=pos;
                    return true;
                }
            }
        }
        check[0][cter[i]]|=1;
        n_count[cter[i]]++;
    }
    return false;
}

int main(){
    if(subprogram()){
        for(int i=0;i<n;i++){
            cout << pr[i] << " ";
        }
        cout << endl;
    }
    else{
        cout << -1 << endl;
    }
    return 0;
}