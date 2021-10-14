#include <iostream>

using namespace std;

int m[100001];

int main(){
    int n,k,i,s,e,v=0,min_length = 0x7FFFFFFF;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        cin >> m[i];
    }
    s=e=0;
    while(true){
        while(e<=n && v<k){
            v += m[++e];
        }
        if(v<k)break;
        min_length = min(min_length,e-s);
        while(s<e && v>=k){
            v -= m[++s];
            if(v>=k)min_length = min(min_length,e-s);
        }
    }
    if(min_length == 0x7FFFFFFF)min_length = 0;
    cout << min_length << endl;
    return 0;
}