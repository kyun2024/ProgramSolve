#include <iostream>

using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    
    long long sum_a = 0;
    int xor_a = 0;
    int m;
    int a,b,i;
    cin >> m;
    for(i=0;i<m;i++){
        cin >> a;
        if(a<3)cin >> b;
        if(a==1){
            sum_a += b;
            xor_a ^= b;
        }
        if(a==2){
            sum_a -= b;
            xor_a ^= b;
        }
        if(a==3){
            cout << sum_a << '\n';
        }
        if(a==4){
            cout << xor_a << '\n';
        }
    }
    return 0;    
}