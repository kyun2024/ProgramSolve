#include <iostream>

using namespace std;

int m[1000001],tr[1000001];

int main(){
    m[1]=0;
    tr[1]=1;
    int i;
    for(i=2;i<=1000000;i++){
        if(i%3==0){
            tr[i]=i/3;
            m[i]=m[i/3]+1;
        }
        if(i%2==0){
            if(m[i]!=0 && m[i]>m[i/2]+1 || m[i]==0){
                tr[i]=i/2;
                m[i]=m[i/2]+1;        
            }
        }
        if(m[i]!=0 && m[i]>m[i-1]+1 || m[i]==0){
            tr[i]=i-1;
            m[i]=m[i-1]+1;
        }
    }
    cin >> i;
    cout << m[i] << endl;
    while(i!=tr[i]){
        cout << i << " ";
        i = tr[i];
    }
    cout << i << endl;
    return 0;
}