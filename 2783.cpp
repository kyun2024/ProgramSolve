#include <iostream>
#include <algorithm>

using namespace std;

double p[101];

int main(){
    double a,b;
    int n,i;
    cin >> a >> b;
    p[0]=b/a;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a >> b;
        p[i]=b/a;
    }
    double max_p = *max_element(p,p+n+1);
    cout << 1000.0/max_p << endl;
    return 0;
}