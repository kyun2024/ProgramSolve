#include <iostream>
#include <algorithm>

using namespace std;

int v[100001];
int m[100001];

int main(){
    int n;
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> v[i];
    }
    m[1]=1;
    for(i=2;i<=n;i++){
        if(m[i-1]<v[i])m[i]=m[i-1]+1;
        else m[i]=v[i];
    }
    cout << *max_element(m+1,m+n+1) << endl;
    return 0;
}