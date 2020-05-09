#include <iostream>

using namespace std;

int main(){
    int n;
    int s,c=0;
    int i;
    cin >> n;
    for(s=1;s<n;s*=2);
    cout << s << " ";
    while(n>0){
        if(n>=s){
            n-=s;
            if(n==0)break;
        }
        s/=2;
        c+=1;
    }
    cout << c << endl;
    return 0;
}