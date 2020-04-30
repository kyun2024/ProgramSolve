#include <iostream>

using namespace std;

int v[1000];

int main(){
    int n;
    int i,res=0,i1,i2;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    i1=i2=0;
    for(i=1;i<n;i++){
        if(v[i-1]<v[i]){
            i2=i;
            if(v[i2]-v[i1]>res){
                res=v[i2]-v[i1];
            }
        }
        else{
            i1=i2=i;
        }
    }
    cout << res << endl;
}