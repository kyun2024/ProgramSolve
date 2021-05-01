#include <iostream>
#include <algorithm>

using namespace std;

int px[100001],py[100001];

int main(){
    int n,m;
    int i,j,k,s,res,x{},y{};
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> py[i] >> px[i];
    }
    s = 0;
    sort(px+1,px+1+m);
    sort(py+1,py+1+m);

    x = px[m/2+1];
    y = py[m/2+1];
    for(k=1;k<=m;k++){
        s += abs(px[k]-x)+abs(py[k]-y);
    }
    cout << s << endl;
    
    return 0;
}