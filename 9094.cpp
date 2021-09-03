#include <iostream>

using namespace std;

int main(){
    int t,n,m;
    int a,b;
    cin >> t;
    while(t--){
        int res=0;
        cin >> n >> m;
        for(a=1;a<n;a++)
            for(b=a+1;b<n;b++)
                if((a*a+b*b+m)%(a*b)==0)
                    res++;
        cout << res << endl;
    }
    return 0;
}
