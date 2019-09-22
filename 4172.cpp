#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    vector<int> V(1000001,0);
    int n{};
    V[0]=1;
    for(int i=1;i<=1e6;i++){
        V[i] = V[int(i-sqrt(i))]+V[int(log(i))]+V[int(i*pow(sin(i),2))];
        V[i] = V[i]%static_cast<int>(1e6);
    }
    while(true){
        cin >> n;
        if(n==-1)break;
        cout << V[n] << endl;
    }
    return 0;
}