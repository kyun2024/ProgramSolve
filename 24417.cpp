#include <iostream>

using namespace std;

int main(){
    int i,n;
    cin >> n;
    int a,b;
    a = b = 1;
    for(i=3;i<=n;i++)
    {
        if(i%2){
            a = (a+b)%1000000007;
        }
        else{
            b = (a+b)%1000000007;
        }
    }
    cout << (n%2?a:b) << " " << max(0,n-2) << endl;
    return 0;
}
