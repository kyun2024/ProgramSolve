#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int N{},M1{},M2{};
    long long int res{};
    vector<int> V;
    cin >> N;
    V.resize(N,0);
    for (auto &x : V){
        cin >> x;
    }
    cin >> M1 >> M2;
    for (auto x: V){
        if(x-M1<=0){
            res+=1;
        }
        else{
            res+=ceil((x-M1)/double(M2))+1;
        }
    }
    cout << res << endl;
    return 0;
}