#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    vector<long long> v;
    v.resize(92,0);
    v[0]=0;
    v[1]=1;
    v[2]=2;
    for(int i=3;i<=91;i++){
        v[i]=v[i-1]+v[i-2];
    }

    long long n;
    int i,j,b;
    ostringstream oss;
    cin >> n;
    for(i=91;i>=1;i--){
        if(v[i]<=n){
            b=i;
            n-=v[i];
            break;
        }
    }
    for(;i>=1;i--){
        if(v[i]<=n){
            oss << 1;
            for(j=b-1;j>i;j--){
                oss << 0;
            }
            b=i;
            n-=v[i];
        }
    }
    oss << 1;
    for(j=b-1;j>=1;j--){
        oss << 0;
    }
    cout << oss.str() << endl;
    return 0;
}