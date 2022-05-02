#include <iostream>

using namespace std;

int main(){
    int n,i,c{};
    cin >> n;
    for(i=1;i*i<n;i++){
        if(n%i==0)c++;
    }
    c*=2;
    if(i*i==n)c++;
    cout << c << endl;
    return 0;
}
