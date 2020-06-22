#include <iostream>

using namespace std;

int calc_price(int a,int b,int c){
    return 1000*(a+10)*(a==b && b==c) + 100*((a+10)*(a==b)+(b+10)*(b==c)+(c+10)*(c==a))*(!(a==b && b==c)) + max(a,max(b,c))*100*(a!=b && b!=c && a!=c);
}
int main(){
    int n,m=0,a,b,c;
    cin >> n;
    while(n--){
        cin >> a >> b >> c;
        m=max(m,calc_price(a,b,c));
    }
    cout << m << endl;
    return 0;
}