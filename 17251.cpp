#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int d[1000001];
int lm[1000001],rm[1000001];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> d[i];
    }
    lm[1]=d[1];
    for(i=2;i<=n;i++){
        lm[i]=max(lm[i-1],d[i]);
    }
    rm[n]=d[n];
    for(i=n-1;i>=1;i--){
        rm[i]=max(rm[i+1],d[i]);
    }
    int l{},r{};
    for(i=1;i<n;i++){
        if(lm[i]>rm[i+1]){
            l+=1;
        }
        else if(lm[i]<rm[i+1]){
            r+=1;
        }
    }
    if(l>r){
        cout << "R" << endl;
    }
    else if(l<r){
        cout << "B" << endl;
    }
    else cout << "X" << endl;
    return 0;
}