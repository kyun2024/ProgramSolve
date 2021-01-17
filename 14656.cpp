#include <iostream>

using namespace std;

int main(){
    int n,a,c=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a;
        if(a!=i)c++;
    }
    cout << c << endl;
    return 0;
}