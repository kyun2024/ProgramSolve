#include <iostream>
#include <vector>

using namespace std;

constexpr int an = 200000;

bool m[400001];

int main(){
    vector<int> v;
    int n,res=0;
    int i,j;
    cin >> n;
    v.resize(n);
    for(i=0;i<n;i++){
        cin >> v[i];
    }
    for(i=0;i<n;i++){
        for(j=0;j<i;j++){
            if(m[v[i]-v[j]+an]){
                res++;
                break;
            }
        }
        for(j=0;j<=i;j++){
            m[v[i]+v[j]+an]=true;
        }
    }
    cout << res << endl;
    return 0;
}