#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,k,c;
    int i1,i2;
    vector<int> v;
    cin >> n >> k;
    v.resize(n+1,1);
    c = n;
    for(i1=1,i2=1;c>0;i1=i1%n+1,i2=i2%k+v[i1]){
        //cout << i1 << " " << v[i1] << endl;
        if(i2==k){
            cout << i1 << " ";
            v[i1]=0;
            c--;
        }
    }
    return 0;
}