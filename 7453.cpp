#include <iostream>
#include <algorithm>

using namespace std;

int ab[16000000];
int cd[16000000];
int abc[16000000];
int cdc[16000000];
int a[4000];
int b[4000];
int c[4000];
int d[4000];

int main(){
    int n,t,i,j;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> t; a[i]=t;
        cin >> t; b[i]=t;
        cin >> t; c[i]=t;
        cin >> t; d[i]=t;
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ab[i*n+j]=a[i]+b[j];
            cd[i*n+j]=c[i]+d[j];
        }
    }
    sort(ab,ab+n*n);
    sort(cd,cd+n*n);
    int abn=0,cdn=0,cn=1;
    for(i=1;i<n*n;i++){
        if(ab[i-1]==ab[i])cn++;
        else{
            abc[abn++]=cn;
            ab[abn]=ab[i];
            cn=1;
        }
    }
    abc[abn++]=cn;

    cn=1;
    for(i=1;i<n*n;i++){
        if(cd[i-1]==cd[i])cn++;
        else{
            cdc[cdn++]=cn;
            cd[cdn]=cd[i];
            cn=1;
        }
    }
    cdc[cdn++]=cn;

    long long res=0;
    i=0;j=cdn-1;
    while(i<abn && j>=0){
        if(ab[i] + cd[j] == 0){
            res += (long long)abc[i]*cdc[j];
            i++;j--;
        }
        else if(ab[i] + cd[j] < 0)i++;
        else j--;
    }
    cout << res << endl;
    return 0;
}