#include <iostream>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

vector<array<long long,10>> v;

int main(){
    int t;
    int kk,i,j,gts;
    long long s = 0;
    cin >> t;
    for(kk=0;kk<t;kk++){
        cin >> gts;
        v.resize(gts+1);
        v[0].fill(1);
        for(i=1;i<=gts;i++){
            s=0;
            for(j=0;j<10;j++){
                s += v[i-1][j];
                v[i][j]=s;
            }
        }
        cout << s << endl;
    }
    return 0;
}