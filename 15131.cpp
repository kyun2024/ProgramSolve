#include <iostream>
#include <climits>

using namespace std;

int m[1000001]={0,0,1,7,4,};

int max(initializer_list<int> l){
    int m=INT_MIN;
    for(const auto& v:l){
        m=max(m,v);
    }
    return m;
}

int main(){
    int i;
    for(i=5;i<=1000000;i++){
        m[i]=max({m[i-2]+1,m[i-3]+7,m[i-4]+4});
    }
    cin >> i;
    cout << m[i] << endl;
    return 0;
}