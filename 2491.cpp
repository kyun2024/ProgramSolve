#include <iostream>

using namespace std;

int a[100001];

int main(){
    int res{},c{},c2{};
    int n;
    int i,j;

    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    res = c = c2 = 1;
    for(i=2;i<=n;i++){
        if(a[i-1]<=a[i]){
            c++;
            res = max(res,c);
        }
        else{
            c=1;
        }
        if(a[i-1]>=a[i]){
            c2++;
            res = max(c2,res);
        }
        else{
            c2=1;
        }
    }
    cout << res << endl;
    return 0;
}