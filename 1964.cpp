#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n+1,0);
    v[0]=1;
    for(int i=1;i<=n;i++){
        v[i]=(v[i-1]+3*i+1)%45678;
    }
    cout << v[n] << endl;
    return 0;
}