#include <iostream>

using namespace std;

int main(){
    int n,t,i=0;
    while(++i){
        cin >> n;
        if(n==0)break;
        while(n--)cin>>t;
        cout << "Case " << i << ": Sorting... done!\n";
    }
    return 0;
}