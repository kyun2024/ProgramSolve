#include <iostream>
#include <vector>

using namespace std;

int main(){
    long long start,end,rng,cnt{};
    long long i,j;
    vector<long long> v;
    cin >> start >> end;
    v.resize(end-start+1,1LL);
    //end = end - start;
    //start = 0LL;
    for(i=2;i*i<=end;i++){
        for(j=start+i*i-(start-1)%(i*i)-1;j<=end;j+=i*i){
            v[j-start]=0;
        }
    }
    for(i=start;i<=end;i++){
        cnt += v[i-start];
        //cout << v[i-start] << " ";
    }
    cout << cnt << endl;
    return 0;
}