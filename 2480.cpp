#include <iostream>

using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << 1000*(a+10)*(a==b && b==c) + 100*((a+10)*(a==b)+(b+10)*(b==c)+(c+10)*(c==a))*(!(a==b && b==c)) + max(a,max(b,c))*100*(a!=b && b!=c && a!=c) << endl;
    return 0;
}