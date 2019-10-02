#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N{},X{};
    vector<int> V;
    cin >> N >> X;
    V.resize(N);
    for(auto &x : V){
        cin >> x;
    }
    for(const auto x: V){
        if(x<X)cout << x << " ";
    }
    cout << endl;
    return 0;
}